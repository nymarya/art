#ifndef _ambient_light_h_
#define _ambient_light_h_

#include "light.h"

namespace art{

    /**
     * @brief Class represent a light that come equally from everywhere
     * 
     */
    class AmbientLight : public Light
    {
        public:
            AmbientLight( Vector3 intensity, std::string name)
                : Light(intensity, name, true) {}
            ~AmbientLight() = default;

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
            /*data */
    };
    
}

#endif