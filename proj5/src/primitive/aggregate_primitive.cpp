#include "../../include/primitive/aggregate_primitive.h"

/**
 * @brief Check if ray intersect with surface of any shape.
 * 
 * @param r 
 * @return true 
 * @return false 
 */
bool art::AggregatePrimitive::intersect( const Ray& r, SurfaceInteraction *) const
{
    bool v;
    // For each primitive aggregate, checks wheter the ray hits the surface
    for (const auto p : primitives)
    {
        v = p->intersect(r, surface);
        if (v)
            return true;
    }
    return false;
}

/**
 * @brief Simpler & faster version of intersection that only return true/false.
 * It does not compute the hit point information.
 */
bool art::AggregatePrimitive::intersect_p( const Ray& r ) const
{
    bool v;
    for (const auto p : primitives)
    {
        v = p->intersect_p(r);
        if (v)
            return true;
    }
    return false;
}