#ifndef _sphere_h_
#define _sphere_h_

#include "shape.h"
#include "../geometry/vector3.h"
#include "../material/material.h"

#include <math.h>

namespace art
{
    class Sphere : public Shape
    {
        public:
            Sphere(Vector3 center, float radius, std::string name, Material *material);
            ~Sphere() = default;

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

            /**
             * @brief   check if a ray intersect a sphere
             * 
             * @param r        the ray
             * @param surface  the surface of primitive
             * @return true    if the ray intersect the sphere
             * @return false   if the ray not intersect the sphere
             */
            bool intersect ( const Ray& r,
                                    SurfaceInteraction * surface)
                                    const;
        
            /**
             * @brief  check if a ray intersect a primitive
             * 
             * @param r        the ray 
             * @return true    if the ray intersect the sphere 
             * @return false   if the ray not intersect the sphere
             */
            bool intersect_p( const Ray& r ) const;

        private:
            Vector3 m_center;
            float m_radius;
};

} // namespace art

#endif