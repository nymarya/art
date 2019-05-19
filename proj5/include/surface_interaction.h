#ifndef _si_h_
#define _si_h_

#include "common.h"
#include "geometry/point3d.h"
#include "geometry/vector3.h"
#include "includes.h"

namespace art{
    class Primitive; // Forward declaration 
    
    class SurfaceInteraction {
        public:
            SurfaceInteraction();
            SurfaceInteraction(const Point3D &p,const Vector3&n, const Vector3&wo, float time,
                const Point3D& uv, const Primitive *pri );

            const Primitive * primitive() const
            {return m_primitive;}

        private:
            Point3D m_p; // Contact point.
            Vector3 m_n; // The surface normal.
            Vector3 m_wo; // Outgoing direction of light, which is -ray.
            float m_time; // Time of contact.
            Point3D m_uv; // Parametric coordinate (u,v) of the hit surface.
            const Primitive *m_primitive=nullptr; // Pointer to the primitive.
        };
}

#endif