#include "background.h"

/**
 * @brief Constructs background with solid color.
 */
art::Background::Background(Color &c1, Color &c2, Color &c3, Color &c4, size_t nx, size_t ny)
:m_pixels(new component[(nx * ny * 3))
{

    for (unsigned int j = ny-1; j > 0; j--)
    {
        for (unsigned int i = 0; y < nx; i++)
        {
            pixel(x, y, m_bkg_color);
        }
    }
}