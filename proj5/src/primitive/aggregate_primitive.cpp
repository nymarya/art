#include "../../include/primitive/aggregate_primitive.h"

/**
 * @brief 
 */
bool art::AggregatePrimitive::intersect(const Ray &r,
               SurfaceInteraction *surface)
    const
{
    bool v;
    for (const auto p : primitives)
    {
        v = p->intersect(r, surface);
        if (v)
            return true;
    }
    return false;
}

/**
 * @brief 
 *  
 */
bool intersect_p(const Ray &r) const
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