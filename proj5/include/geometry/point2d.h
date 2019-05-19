#ifndef _point2d_h_
#define _point2d_h_

#include "../common.h"

namespace art
{

/**
 * @brief Class representing a two dimensional point.
 */
class Point2D
{

  public:
	/**
	 * @brief Contructor for point object
	 * @param x X coordinate.
	 * @param y Y coordinate.
	 */
	Point2D(coord_type x = 0, coord_type y = 0);

	/**
	 * Default destructor.
	 */
	~Point2D() = default;

	/**
	 * @brief Return the x-coordinate.
	 */
	coord_type x() const;

	/**
	 * @brief Return the y-coordinate.
	 */
	coord_type y() const;

  private:
	coord_type m_x;

	coord_type m_y;
};
} // namespace rstzr

#endif