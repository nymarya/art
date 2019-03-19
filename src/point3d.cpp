#include "../include/point3d.h"

/**
 * @brief Contructor for point object
 * @param x X coordinate.
 * @param y Y coordinate.
 */
art::Point3D::Point3D(coord_type x, coord_type y, coord_type z)
    : m_x(x), m_y(y), m_z(z)
{ /*empty*/
}

/**
 * @brief Return the x-coordinate.
 */
coord_type art::Point3D::x() const
{
    return m_x;
}

/**
 * @brief Return the y-coordinate.
 */
coord_type art::Point3D::y() const
{
    return m_y;
}

/**
 * @brief Return the z-coordinate.
 */
coord_type art::Point3D::z() const
{
    return m_z;
}