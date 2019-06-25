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
                : Light(intensity, name) {}
            ~AmbientLight() = default;
        private:
            /*data */
    };
    
}

#endif