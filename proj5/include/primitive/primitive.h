#ifndef _primitive_h_
#define _primitive_h_

#include <memory>

#include "../includes.h"
#include "../ray.h"
#include "../material/material.h"

namespace art{

    class SurfaceInteraction;

    class Primitive {
        public:
            Primitive(){}

            virtual ~Primitive() {};
            virtual bool intersect( const Ray& r, SurfaceInteraction *) const = 0;
            // Simpler & faster version of intersection that only return true/false.
            // It does not compute the hit point information.
            virtual bool intersect_p( const Ray& r ) const = 0;
            virtual Material * get_material(void) const = 0;
    };
}

#endif