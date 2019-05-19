#include "../../include/primitive/geometric_primitive.h"

/**
 * @brief Check if ray intersetc with surface of the shape.
 */
bool art::GeometricPrimitive::intersect( const Ray& r, SurfaceInteraction *surface) const
{
    return m_shape->intersect(r, surface);
}

/**
 * @brief Simpler & faster version of intersection that only return true/false.
 * It does not compute the hit point information. 
 */
bool art::GeometricPrimitive::intersect_p( const Ray& r ) const
{
    return m_shape->intersect_p(r);
}