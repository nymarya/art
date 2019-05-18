#ifndef _flat_material_h_
#define _flat_material_h_

#include <iostream>

#include "material.h"
#include "../geometry/vector3.h"

namespace art
{
    class FlatMaterial : public Material
    {
        public:
            FlatMaterial(component_t r, component_t g, component_t b, std::string name);
            ~FlatMaterial();

            /**
             * @brief Get diffuse material/color.
             * 
             * @return Vector3 
             */
            Vector3 diffuse();

        private:
            Vector3 m_rgb;
    };

} // namespace art

#endif