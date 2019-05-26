#include "../../include/primitive/aggregate_primitive.h"

/**
 * @brief Instatiate the new aggregate of primitive based on
 * a list of primitives.
 */ 
art::AggregatePrimitive::AggregatePrimitive(std::vector<std::shared_ptr<Primitive>> primitives)
:m_primitives(primitives), Primitive(*primitives.front().get())
{
    /*empty*/
}

/**
 * @brief Check if ray intersect with surface of any shape.
 * 
 * @param r 
 * @return true 
 * @return false 
 */
bool art::AggregatePrimitive::intersect( const Ray& r, SurfaceInteraction * s) const
{
    bool v;
    // For each primitive aggregate, checks wheter the ray hits the surface
    for (const auto p : m_primitives)
    {
        v = p->intersect(r, s);
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
    for (const auto p : m_primitives)
    {
        v = p->intersect_p(r);
        if (v)
            return true;
    }
    return false;
}