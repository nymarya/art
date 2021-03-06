#ifndef _geometric_primitive_h_
#define _geometric_primitive_h_

#include <memory>
#include "primitive.h"
#include "../shape/shape.h"
#include "../material/material.h"

namespace art
{
class GeometricPrimitive : public Primitive
{
        public:
            GeometricPrimitive(std::shared_ptr<Shape> shape,
                            std::shared_ptr<Material> material);
            ~GeometricPrimitive() = default;

            /**
             * @brief Check if ray intersetc with surface of the shape.
             * 
             * @param r 
             * @return true 
             * @return false 
             */
            bool intersect(const Ray &r, SurfaceInteraction *) const;

            /**
             * @brief Simpler & faster version of intersection that only return true/false.
             * It does not compute the hit point information.
             * 
             * @param r 
             * @return true 
             * @return false 
             */
            bool intersect_p(const Ray &r) const;

            Material *get_material(void) const override
            {
                return m_material.get();
            }

        private:
            std::shared_ptr<Shape> m_shape;
            std::shared_ptr<Material> m_material;
};

} // namespace art

#endif