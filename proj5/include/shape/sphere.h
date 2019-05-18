#ifndef _sphere_h_
#define _sphere_h_

#include "shape.h"
#include "../geometry/vector3.h"
#include "../material/material.h"

namespace art
{
    class Sphere : public Shape
    {
        public:
            Sphere(Vector3 center, float radius, std::string name, Material *material);
            ~Sphere();

            /**
             * @brief Get center of the sphere
             * 
             * @return Vector3 
             */
            Vector3 center();

            /**
             * @brief Get radius of the sphere
             * 
             * @return float 
             */
            float radius();

        private:
            Vector3 m_center;
            float m_radius;
};

} // namespace art

#endif