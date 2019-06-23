#include "../../include/shape/sphere.h"
#include <math.h>

art::Sphere::Sphere(art::Vector3 center, float radius, std::string name, art::Material *material)
    : Shape(name, material), m_center(center), m_radius(radius)
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

/**
 * @Override 
 * 
 * @brief   check if a ray intersect a sphere.
 */
bool art::Sphere::intersect(const art::Ray &r,
               art::SurfaceInteraction *surface) const
{
    // Equation from "Line-sphere intersection" article
    // @see https://en.wikipedia.org/wiki/Line–sphere_intersection

    Vector3 oc = r.o() - m_center;

    Vector3 d = r.d();

    float b = oc * d;
    float c = (oc * oc) - (m_radius * m_radius);

    float discriminant = b*b - c ;
    if(discriminant > 0)
    {
        float temp = (-b - sqrt(discriminant) ) ;
        if(( temp < r.tMax()) & (temp > r.tMin()))
        {
            surface->time(temp);
            surface->p( r.at(temp) );
            surface->n( (surface->p() - m_center) / m_radius );
            surface->wo( (d - r.o()) * -1.0f );

            return true;
        }

        temp = (-b + sqrt(discriminant) );
        if( (temp < r.tMax()) & (temp > r.tMin()))
        {
            surface->time(temp);
            surface->p( r.at(temp) );
            surface->n( (surface->p() - m_center) / m_radius );
            surface->wo( (d - r.o()) * -1.0f );

            return true;
        }

    }
    return false;
}

/**
 * @brief  check if a ray intersect a primitive
 * @Override
 */
bool art::Sphere::intersect_p(const art::Ray &r) const
{
    // Equation from "Raytracing In One Weekend" book
    Vector3 oc = r.o() - m_center;

    Vector3 d = r.d();

    float a = d * d;
    float b = oc * d;
    float c = (oc * oc) - (m_radius * m_radius);

    float discriminant = b*b - a*c;

    return (discriminant >= 0.0);
}