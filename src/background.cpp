#include "background.h"

/**
 * @brief Constructs background with solid color.
 */
art::Background::Background(Color &c, std::string type)
:m_type(type)
{
    m_colors.push_back(Vector3(c.red()/255.0, c.green()/255.0, c.blue()/255.0) );
}

/**
 * @brief Constructs background with solid color.
 */
art::Background::Background(Color &c1, Color &c2, Color &c3, Color &c4, std::string type)
:m_type(type)    
{
    m_colors.push_back(Vector3((component_t)c1.red()/255, (component_t)c1.green()/255, (component_t)c1.blue()/255));
    m_colors.push_back(Vector3((float)c2.red()/255, (float)c2.green()/255, (float)c2.blue()/255));
    m_colors.push_back(Vector3((float)c3.red()/255, (float)c3.green()/255, (float)c3.blue()/255));
    m_colors.push_back(Vector3((float)c4.red()/255, (float)c4.green()/255, (float)c4.blue()/255));

}


void art::Background::pixel(size_t x, size_t y, Color &c)
{
}

/**
 * @brief
 *  C2  C3
 *  C1  C4
 */
art::Vector3 art::Background::billinear(float t_x, float t_y)
{

    auto red_c1 = m_colors[0][RGB::RED];
    auto red_c2 = m_colors[1][RGB::RED];
    auto red_c3 = m_colors[2][RGB::RED];
    auto red_c4 = m_colors[3][RGB::RED];

    auto green_c1 = m_colors[0][RGB::GREEN];
    auto green_c2 = m_colors[1][RGB::GREEN];
    auto green_c3 = m_colors[2][RGB::GREEN];
    auto green_c4 = m_colors[3][RGB::GREEN];

    auto blue_c1 = m_colors[0][RGB::BLUE];
    auto blue_c2 = m_colors[1][RGB::BLUE];
    auto blue_c3 = m_colors[2][RGB::BLUE];
    auto blue_c4 = m_colors[3][RGB::BLUE];

    //Interpolate twice on the x axis
    // Bottom
    double new_red_1 = red_c1 + (red_c4 - red_c1) * t_x;
    double new_green_1 = green_c1 + (green_c4 - green_c1) * t_x;
    double new_blue_1 = blue_c1 + (blue_c4 - blue_c1) * t_x;
    // Top
    double new_red_2 = red_c2 + (red_c3 - red_c2) * t_x;
    double new_green_2 = green_c2 + (green_c3 - green_c2) * t_x;
    double new_blue_2 = blue_c2 + (blue_c3 - blue_c2) * t_x;

    // Interpolate on the y axis
    double new_red = new_red_1 + (new_red_2 - new_red_1) * t_y;
    double new_green = new_green_1 + (new_green_2 - new_green_1) * t_y;
    double new_blue = new_blue_1 + (new_blue_2 - new_blue_1) * t_y;

    return Vector3(new_red, new_green, new_blue);
}

/**
* @brief Get the pixel color from background.
*/
art::Vector3 art::Background::color(float i, float j)
{
    if( m_type == "solid")
        return m_colors[0];
    else{
       return billinear(i, j); 
    }
}