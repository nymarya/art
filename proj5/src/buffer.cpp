#include "buffer.h"


/**
 * @brief Constructor Default
 */
art::Buffer::Buffer(const size_t width, const size_t height)
    : m_width(width), m_height(height), m_pixels(new element_t[(width * height * 3)]),
      m_fill_color(Color((color_t)255, (color_t)0, (color_t)0)),
      m_stroke_color(Color((color_t)0, (color_t)0, (color_t)0)), 
      m_bkg_color(Color((color_t)255, (color_t)255, (color_t)255))
{

    for (unsigned int x = m_height-1; x >0; x--)
    {
        for (unsigned int y = 0; y < m_width; y++)
        {
            pixel(y, x, m_bkg_color);
        }
    }
}

/**
*@brief Copy constructor.
*/
art::Buffer &art::Buffer::operator=(Buffer &other)
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
void art::Buffer::pixel(const long x, const long y, const Color &c)
{
    m_pixels[ y * m_width + x ] = c.red();
    m_pixels[y * m_width + x + m_width * m_height ] = c.green();
    m_pixels[y * m_width + x + m_width * m_height * 2] = c.blue();
}

/**
 * @brief Set the color of a pixel on the canvas
 */
//TODO: change x and y to Point2D
void art::Buffer::pixel(const long x, const long y, const art::Vector3 &v)
{
    if(x < 0u || (size_t)x >= m_width || y < 0u || (size_t)y >= m_height )
		return;
          
    m_pixels[y * m_width + x  ] = v[RGB::RED] * 255;
    m_pixels[y * m_width + x + m_width * m_height ] = v[RGB::GREEN] * 255;
    m_pixels[y * m_width + x + m_width * m_height * 2] = v[RGB::BLUE] * 255;
}

/**
 * @brief Get the pixel color from canvas
 */
element_t  art::Buffer::pixel(const long x, const long y) const
{
    return m_pixels[x*(m_height*m_width) + y*m_width ];
}

/**
 * @brief Get the color of a pixel from canvas
 */
art::Color art::Buffer::color(const long x, const long y) const
{
    auto red = m_pixels[y * m_width + x ];
    auto green = m_pixels[y * m_width + x + m_width * m_height ];
    auto blue = m_pixels[y * m_width + x + m_width * m_height * 2];

    return Color(red, green, blue);
}

/**
 * @brief Get the canvas width
 */
size_t art::Buffer::width(void) const
{
    return m_width;
}

/**
 * @brief Get the canvas width
 */
void art::Buffer::width(size_t width)
{
    m_width = width;
}

/**
 * @brief Get the canvas height
 */
size_t art::Buffer::height(void) const
{
    return m_height;
}

/**
 * @brief Get the canvas width
 */
void art::Buffer::height(size_t height)
{
    m_height = height;
}

/**
 * @brief Get the canvas pixels as an array of unsigned char.
 */
element_t  *art::Buffer::pixels(void) const
{
    return m_pixels.get();
}

void art::Buffer::bkg_color(const Color &c)
{
    m_bkg_color = c;
}

void art::Buffer::fill_color(const Color &c)
{
    m_fill_color = c;
}

/**
 * @brief Get the color that will fill the object
 */
art::Color art::Buffer::fill_color() const
{
    return m_fill_color;
}

/**
 * @brief Get the color that will draw the object
 */
void art::Buffer::stroke_color(const Color &c)
{
    m_stroke_color = c;
}

/**
 * @brief Get the color that will draw the object
 */
art::Color art::Buffer::stroke_color() const
{
    return m_stroke_color;
}
