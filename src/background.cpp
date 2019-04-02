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
 * @brief Constructs background with 4 colors(gradient).
 */
art::Background::Background(Color &c1, Color &c2, Color &c3, Color &c4, std::string type)
:m_type(type)    
{
    m_colors.push_back(Vector3((component_t)c1.red()/255, (component_t)c1.green()/255, (component_t)c1.blue()/255));
    m_colors.push_back(Vector3((float)c2.red()/255, (float)c2.green()/255, (float)c2.blue()/255));
    m_colors.push_back(Vector3((float)c3.red()/255, (float)c3.green()/255, (float)c3.blue()/255));
    m_colors.push_back(Vector3((float)c4.red()/255, (float)c4.green()/255, (float)c4.blue()/255));

}


/**
 * @brief
 *  C2  C3
 *  C1  C4
 */
art::Vector3 art::Background::billinear(float t_x, float t_y)
{
    //Interpolate twice on the x axis
    // Bottom
    Vector3 color_bottom = m_colors[0] + (m_colors[3] - m_colors[0]) * t_x;
    
    // Top
    Vector3 color_top = m_colors[1] + (m_colors[2] - m_colors[1]) * t_x;

    // Interpolate on the y axis
    Vector3 new_color = color_bottom + (color_top - color_bottom) * t_y;

    return new_color;
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