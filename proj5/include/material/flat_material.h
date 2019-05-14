#ifndef _flat_material_h_
#define _flat_material_h_

#include "material.h"
#include "../vector3.h"

namespace art
{
    class FlatMaterial : public Material
    {
        public:
            FlatMaterial(component_t r, component_t g, component_t b);
            ~FlatMaterial();

        private:
            Vector3 rgb;
    };

} // namespace art

#endif