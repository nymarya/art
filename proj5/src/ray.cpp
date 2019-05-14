#include "ray.h"

art::Ray::Ray(const Point3& o, const Vector3& d )
:m_o (o), m_d(d)
{/*empty*/}

art::Point3 art::Ray::operator() (component_t t) { 
    return this->m_o + (this->m_d * t); 
} 
