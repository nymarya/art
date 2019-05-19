#ifndef _point3d_h_
#define _point3d_h_

#include "../common.h"

namespace art
{

/**
 * @brief Class representing a two dimensional point.
 */
class Point3D
{

  public:
	/**
	 * @brief Contructor for point object
	 * @param x X coordinate.
	 * @param y Y coordinate.
	 * @param z Z coordinate.
	 */
	Point3D(coord_type x = 0, coord_type y = 0, coord_type z = 0);

	/**
	 * Default destructor.
	 */
	~Point3D() = default;

	/**
	 * @brief Return the x-coordinate.
	 */
	coord_type x() const;

	/**
	 * @brief Return the y-coordinate.
	 */
	coord_type y() const;

	/**
	 * @brief Return the z-coordinate.
	 */
	coord_type z() const;

  private:
	coord_type m_x;

	coord_type m_y;

	coord_type m_z;
};
} // namespace rstzr

#endif