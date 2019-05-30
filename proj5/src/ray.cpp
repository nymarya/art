#include "../include/ray.h"

art::Ray::Ray(const Point3& o, const Vector3& d )
:m_o (o), m_d(d)
{/*empty*/}

art::Point3 art::Ray::at(const component_t t) const { 
    return m_o + ( m_d * t); 
} 

/**
 * @brief Get the x axis that generated the ray
 */
component_t art::Ray::x() const
{
    return m_x;
}

/**
 * @brief Set the x axis that generated the ray
 */
void art::Ray::x(int x)
{
    m_x = x;
}

/**
 * @brief Get the y axis that generated the ray
 */
component_t art::Ray::y() const
{
    return m_y;
}

/**
 * @brief Set the y axis that generated the ray
 */
void art::Ray::y( int y)
{
    m_y = y;
}

/**
 * @brief Get x and y of the ray.
 */
std::tuple<float, float> art::Ray::uv() const
{
    float phi = atan2(m_d.z(), m_d.x());
    float theta = asin(m_d.y());
    float u = 1-(phi + M_PI) / (2 * M_PI);
    float v = (theta + M_PI/2) /M_PI;

    return std::make_tuple(u, v);
}
