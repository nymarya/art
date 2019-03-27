#include "canvas.h"


/**
 * @brief Constructor Default
 */
art::Canvas::Canvas(const size_t width, const size_t height)
    : m_width(width), m_height(height), m_pixels(new element_t[(width * height * 3)]),
      m_stroke_color(Color((color_t)0, (color_t)0, (color_t)0)), 
      m_bkg_color(Color((color_t)255, (color_t)255, (color_t)255)),
      m_fill_color(Color((color_t)255, (color_t)0, (color_t)0))
{

    for (unsigned int x = 0; x < m_width; x++)
    {
        for (unsigned int y = 0; y < m_height; y++)
        {
            pixel(x, y, m_bkg_color);
        }
    }
}

/**
*@brief Copy constructor.
*/
art::Canvas &art::Canvas::operator=(Canvas &other)
{

    m_width = other.m_width;
    m_height = other.m_height;
    m_bkg_color = other.m_bkg_color;
    m_stroke_color = other.m_stroke_color;
    m_fill_color = other.m_fill_color;

    auto size = m_width * m_height * 3;

    m_pixels = std::make_unique<element_t []>(size);

    for (auto i = 0u; i < size; i++)
        m_pixels.get()[i] = other.m_pixels.get()[i];

    return *this;
}

/**
 * @brief Set the color of a pixel on the canvas
 */
//TODO: change x and y to Point2D
void art::Canvas::pixel(const long x, const long y, const Color &c)
{
    // m_pixels[(x*m_width)+y] = c;
    m_pixels[m_width * y + x] = c.red();
    m_pixels[m_height * m_width + m_width * y + x] = c.green();
    m_pixels[m_height * m_width * 2 + m_width * y + x] = c.blue();
}

/**
 * @brief Set the color of a pixel on the canvas
 */
//TODO: change x and y to Point2D
void art::Canvas::pixel(const long x, const long y, const art::Vector3 &v)
{
    // m_pixels[(x*m_width)+y] = c;
    m_pixels[m_width * y + x] = v[RGB::RED] * 255;
    m_pixels[m_height * m_width + m_width * y + x] = v[RGB::GREEN] * 255;
    m_pixels[m_height * m_width * 2 + m_width * y + x] = v[RGB::BLUE] * 255;
}

/**
 * @brief Get the pixel color from canvas
 */
element_t  art::Canvas::pixel(const long x, const long y) const
{
    return m_pixels[(x * m_width) + y];
}

/**
 * @brief Get the color of a pixel from canvas
 */
art::Color art::Canvas::color(const long x, const long y) const
{
    auto red = m_pixels[m_width * y + x];
    auto green = m_pixels[m_height * m_width + m_width * y + x];
    auto blue = m_pixels[m_height * m_width * 2 + m_width * y + x];

    return Color(red, green, blue);
}

/**
 * @brief Get the canvas width
 */
size_t art::Canvas::width(void) const
{
    return m_width;
}

/**
 * @brief Get the canvas width
 */
void art::Canvas::width(size_t width)
{
    m_width = width;
}

/**
 * @brief Get the canvas height
 */
size_t art::Canvas::height(void) const
{
    return m_height;
}

/**
 * @brief Get the canvas width
 */
void art::Canvas::height(size_t height)
{
    m_height = height;
}

/**
 * @brief Get the canvas pixels as an array of unsigned char.
 */
element_t  *art::Canvas::pixels(void) const
{
    return m_pixels.get();
}

void art::Canvas::bkg_color(const Color &c)
{
    m_bkg_color = c;
}

void art::Canvas::fill_color(const Color &c)
{
    m_fill_color = c;
}

/**
 * @brief Get the color that will fill the object
 */
art::Color art::Canvas::fill_color() const
{
    return m_fill_color;
}

/**
 * @brief Get the color that will draw the object
 */
void art::Canvas::stroke_color(const Color &c)
{
    m_stroke_color = c;
}

/**
 * @brief Get the color that will draw the object
 */
art::Color art::Canvas::stroke_color() const
{
    return m_stroke_color;
}
