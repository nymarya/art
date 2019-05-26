#include "../../include/primitive/geometric_primitive.h"

art::GeometricPrimitive::GeometricPrimitive(std::shared_ptr<Shape> shape,
                         std::shared_ptr<Material> material)
:m_shape{shape}, m_material(material)
{
    if(material.get() == nullptr)
     std::cout << "geo material ugh\n";
    else
    {
        std::cout<< "geo material ok\n";
    }
    
}

/**
 * @brief Check if ray intersetc with surface of the shape.
 */
bool art::GeometricPrimitive::intersect( const Ray& r, SurfaceInteraction *surface) const
{
    bool hit =  m_shape->intersect(r, surface);
    if(!hit)
        return false;

    surface->primitive(this);
    return true;
}

/**
 * @brief Simpler & faster version of intersection that only return true/false.
 * It does not compute the hit point information. 
 */
bool art::GeometricPrimitive::intersect_p( const Ray& r ) const
{
    return m_shape->intersect_p(r);
}