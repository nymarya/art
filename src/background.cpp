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
    auto red1 = c1.red();
    auto red2 = c2.red();
    auto n_red_y0 = red2 - red1;
    auto n_red_y1 = c4.red() - c3.red();
    auto n_red_x_0 = c3.red() - c1.red();
    auto n_red_x_1 = c4.red() - c2.red();

    auto green1 = c1.green();
    auto green2 = c2.green();
    auto n_green_y0 = green2 - green1;
    auto n_green_y1 = c4.green() - c3.green();
    auto n_green_x_0 = c3.green() - c1.green();
    auto n_green_x_1 = c4.green() - c2.green();

    auto blue1 = c1.blue();
    auto blue2 = c2.blue();
    auto n_blue_y0 = blue2 - blue1;
    auto n_blue_y1 = c4.blue() - c3.blue();
    auto n_blue_x_0 = c3.blue() - c1.blue();
    auto n_blue_x_1 = c4.blue() - c2.blue();

    float r = c1.red() * 100 / 255;
    float g = c1.green() * 100 / 255;
    float b = c1.blue() * 100 / 255;

    for (unsigned int i = 0; i < width; i++)
    {
        for (unsigned int j = 0; j < height; j++)
        {
            // Color pixels

            // Get new colors
            float r = float(j) * (n_red_y1 - n_red_y0) + ((-n_red_x_0) / (n_red_x_1 - n_blue_x_0));
        }
    }
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