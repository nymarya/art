#ifndef _canvas_h_
#define _canvas_h_

#include <iostream>
#include <algorithm>
#include <iterator>
#include <memory>
#include <math.h>

#include "vector3.h"
#include "color.h"
#include "common.h"

using element_t = unsigned char;

namespace art
{

class Canvas
{

 public:
   /**
   * @brief Constructor Default
   */

   Canvas() = default;
   Canvas(std::size_t width, std::size_t height);

   /**
    *@brief Copy constructor.
    */
   Canvas &operator=(Canvas &other);

   /**
             * @brief  Destructor default
             */
   ~Canvas() = default;

   /**
             * @brief Set the color of a pixel on the canvas
             */
   void pixel(const long x, const long y, const Color &c);
   void pixel(const long x, const long y, const Vector3 &v);

   /**
     * @brief Get the pixel color from canvas
     */
   element_t  pixel(const long x, const long y) const;

    /**
     * @brief Get the color of a pixel from canvas
     */
   Color color(const long x, const long y) const;

   /**
     * @brief Get the canvas' width
     */
   size_t width(void) const;

   /**
     * @brief Get the canvas' width
     */
   void width(const size_t);

   /**
     * @brief Get the canvas' height
     */
   size_t height(void) const;

   /**
     * @brief Get the canvas' height
     */
   void height(const size_t);

   /**
     * @brief Get the canvas pixels as an array of unsigned char.
     */
   element_t  *pixels(void) const;

   void bkg_color(const Color &c);

   void fill_color(const Color &c);

   /**
     * @brief Get the color that will fill the object
     */
   Color fill_color() const;

   /**
    * @brief Set the color that will draw the object.
    */
   void stroke_color(const Color &c);

   /**
     * @brief Get the color that will draw the object
     */
   Color stroke_color() const;

 private:
   size_t m_width;

   size_t m_height;

   //n x m x 3
   std::unique_ptr<element_t[]> m_pixels;

   Color m_fill_color, m_stroke_color;

   Color m_bkg_color;
};

} // namespace art

#endif