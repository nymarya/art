#ifndef _si_h_
#define _si_h_

#include "common.h"
#include "point3d.h"
#include "vector3.h"

namespace art{
    class SurfaceInteraction {
        public:
            SurfaceInteraction(const Point3Dt&p,const Vector3&n, const Vector3&wo, float time
                const Point3D& uv, const Primitive *pri )
                : p{p}, n{n}, wo{wo}, time{time}, uv{uv}, primitive{pri}{};

            Point3D p; // Contact point.
            Vector3 n; // The surface normal.
            Vector3 wo; // Outgoing direction of light, which is -ray.
            float time; // Time of contact.
            Point3D uv; // Parametric coordinate (u,v) of the hit surface.
            const Primitive *primitive=nullptr; // Pointer to the primitive.
        };
}

#endif