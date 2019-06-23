#include "../include/ray.h"

art::Ray::Ray(const Point3& o, const Vector3& d )
:m_o (o), m_d(d)
{/*empty*/}

art::Point3 art::Ray::at(const component_t t) const { 
    return m_o + ( m_d * t); 
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
