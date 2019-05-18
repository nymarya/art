#ifndef _primitive_h_
#define _primitive_h_

#include "../ray.h"
#include "../material/material.h"
#include "../includes.h"

namespace art{

    class Primitive {
        public:
            Primitive(std::shared_ptr<Material> material)
            :m_material(material){}

            virtual ~Primitive();
            virtual bool intersect( const Ray& r, SurfaceInteraction *) const = 0;
            // Simpler & faster version of intersection that only return true/false.
            // It does not compute the hit point information.
            virtual bool intersect_p( const Ray& r ) const = 0;
            virtual const Material * get_material(void) const {return m_material.get();}
        private:
            std::shared_ptr<Material> m_material;
    };
}

#endif