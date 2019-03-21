#include "background.h"

/**
 * @brief Constructs background with solid color.
 */
art::Background::Background(Color &c, size_t w, size_t h)
: m_width(w), m_height(h), m_pixels(new component[(w * h * 3)])
{
    for (unsigned int x = 0; x < m_width; x++)
    {
        for (unsigned int y = 0; y < m_height; y++)
        {
            pixel(x, y, c);
        }
}
}

/**
 * @brief Constructs background with solid color.
 */
art::Background::Background(Color &c1, Color &c2, Color &c3, Color &c4, size_t width, size_t height)
    : m_width(width), m_height(height), m_pixels(new component[(width * height * 3)])
{
    bilinear(c1, c2, c3, c4);
}

component* art::Background::pixels() const{
    return m_pixels.get();
}

size_t art::Background::width() const{
    return m_width;
}

size_t art::Background::height() const{
    return m_height;
}

void art::Background::pixel( size_t x, size_t y, Color &c){
    m_pixels[m_width * y + x] = c.red();
    m_pixels[m_height * m_width + m_width * y + x] = c.green();
    m_pixels[m_height * m_width * 2 + m_width * y + x] = c.blue();
}

void art::Background::bilinear( Color &c1, Color &c2, Color &c3, Color &c4 ){
    float r = c1.red()   / 255;
    float g = c1.green() / 255;
    float b = c1.blue()  / 255;
    //f(x,y) = (y2-y)/(y2-y1)*( (x2-x)/(x2-x1)*f(q11) + (x-x1)/(x2-x1)*f(q21) )  
    //         + (y-y1)/(y2-y1) *( (x2-x)/(x2-x1)*f(q12) + (x-x1)/(x2-x1)*f(q22) )  

    double center_x = m_width/2.0;
    double center_y = m_height/2.0;
    for (unsigned int i = 0; i < m_height; i++)
    {
        int relative_y = center_y -i;	
        for (unsigned int j = 0; j < m_width; j++)
        {
            int relative_x = j - center_x;	

            // get x coordinate between current x and the begin of the image
            double x_begin = rand() % relative_x;
            double x_end   = rand() % m_width + relative_x;
            // get y coordinate between current y and the begin of the image
            double y_begin = rand() % relative_y;
            // get y coordinate between current y and the end of the image
            double y_end   = rand() % (m_height-relative_y) + relative_y;

            // Get the points to interpolate
            int q12x = floor(x_begin);
            int q12y = floor(y_begin);
            int q22x = ceil(x_end);
            int q22y = q12y;
            int q11x = q12x;
            int q11y = ceil(y_end);
            int q21x = q22x;
            int q21y = q11y;

            // Get the color pixels
            auto tl = color(q12x, q12y);
            auto red_tl = tl.red();
            auto green_tl = tl.green();
            auto blue_tl = tl.blue();

            auto tr = color(q22x, q22y);
            auto red_tr = tr.red();
            auto green_tr = tr.green();
            auto blue_tr = tr.blue();

            auto bl = color(q11x, q11y);
            auto red_bl = bl.red();
            auto green_bl = bl.green();
            auto blue_bl = bl.blue();

            auto br = color(q21x, q21y);
            auto red_br = br.red();
            auto green_br = br.green();
            auto blue_br = br.blue();

            // Interpolate in the x-direction: y1
            float delta_x = q21x - q11x;
            float delta_x1 = delta_x == 0 ? 1: (q21x - center_x)/ delta_x;
            float delta_x2 = delta_x == 0 ? 0: (center_x - q11x)/delta_x;

            float red_b1 = delta_x1 * red_bl + delta_x2 * red_br;
            float green_b1 = delta_x1 * green_bl + delta_x2 * green_br;
            float blue_b1 = delta_x1 * blue_bl + delta_x2 * blue_br;

            // Interpolate in the x-direction:y2
            float delta_x_2 = q22x - q12x;
            float delta_x1_2 = delta_x_2 == 0 ? 1: (q22x - center_x)/ delta_x;
            float delta_x2_2 = delta_x_2 == 0 ? 0: (center_x - q12x)/delta_x;

            float red_b2 = delta_x1_2 * red_tl + delta_x2_2 * red_tr;
            float green_b2 = delta_x1_2 * green_tl + delta_x2_2 * green_tr;
            float blue_b2 = delta_x1_2 * blue_tl + delta_x2_2 * blue_tr;

            // Interpolate in the y-direction
            float delta_y = q12y - q11y;
            float delta_y1 = delta_y == 0 ? 1: (q12y - center_y)/ delta_y;
            float delta_y2 = delta_y == 0 ? 0: (center_y - q11y)/delta_y;

            auto new_red = delta_y * red_b1 + delta_y * red_b2;
            auto new_green = delta_y * green_b1 + delta_y * green_b2;
            auto new_blue = delta_y * blue_b1 + delta_y * blue_b2;

            Color c = Color(new_red, new_green, new_blue);
            pixel(j, i, c);
        }
    }
}

/**
* @brief Get the pixel color from background.
*/
art::Color art::Background::color(const long x, const long y) const
{
    auto red = m_pixels[m_width * y + x];
    auto green = m_pixels[m_height * m_width + m_width * y + x];
    auto blue = m_pixels[m_height * m_width * 2 + m_width * y + x];

    return Color(red, green, blue);
}