#ifndef _sphere_h_
#define _sphere_h_

#include "shape.h"
#include "../point3d.h"

namespace art {
    class Sphere
    {
        
        public:
            Sphere(Point3D center, float radius);
            ~Sphere();
        private:
            Point3D m_center;
            float m_radius;
    };

    
}

#endif