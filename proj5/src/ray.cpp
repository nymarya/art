#include "../include/ray.h"

art::Ray::Ray(const Point3& o, const Vector3& d )
:m_o (o), m_d(d)
{/*empty*/}

art::Point3 art::Ray::operator() (component_t t) const { 
    return this->m_o + ( this->m_d * t); 
} 

/**
 * @brief Get the x axis that generated the ray
 */
component_t art::Ray::x()
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
component_t art::Ray::y()
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
