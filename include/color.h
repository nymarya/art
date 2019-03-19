#ifndef _color_h_
#define _color_h_

#include <iostream>

using color_t = unsigned char;

namespace art
{

class Color
{

public:
  Color() = default;
  Color(color_t red, color_t green, color_t blue);

  /**
   * TODO: Construtor receives the percentage of that color
   * Color( float red, float green, float blue);
   */

  ~Color() = default;

  Color &operator=(const Color &other);

  /**
   * @brief Override operator 'equal'
   */
  bool operator==(const Color &other) const;

  color_t red() const;

  color_t green() const;

  color_t blue() const;

private:
  color_t *m_channels;
};
} // namespace rstzr

#endif