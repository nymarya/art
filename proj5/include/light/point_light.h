#ifndef _point_light_h_
#define _point_light_h_

#include "light.h"

namespace art{

    /**
     * @brief Class represeting an infinitely small sphere of light with a 
     * 3D location in space that emits light rays in all directions
     */
    class PointLight : public Light
    {
        public:
            PointLight( Vector3 intensity, std::string name, Vector3 position)
                : Light(intensity, name), m_position(position) {}
            ~PointLight() = default;

            /**
             * @brief Calculates the contribution of the light
             * 
             * @param isect 
             * @param wi 
             * @param vt 
             * @return Vector3 
             */
            Vector3 Li( const SurfaceInteraction &isect, Vector3 *wi, 
                                VisibilityTester *vt) override;
        private:
            Vector3 m_position; // The position of the light (x y z)
    };
    
}

#endif