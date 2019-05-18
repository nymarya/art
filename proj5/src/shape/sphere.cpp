#include "../../include/shape/sphere.h"

art::Sphere::Sphere(art::Vector3 center, float radius, std::string name, art::Material *material)
:m_center (center), m_radius(radius), Shape(name, material)
{

}

/**
 * @brief Get center of the sphere
 * 
 * @return Vector3 
 */
art::Vector3 art::Sphere::center()
{
    return m_center;
}

/**
 * @brief Get radius of the sphere
 * 
 * @return float 
 */
float art::Sphere::radius()
{
    return m_radius;
}