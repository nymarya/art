#ifndef _light_h_
#define _light_h_

#include "../geometry/vector3.h"

namespace art{

    /**
     * @brief Base class for any light used on a scene
     * 
     */
    class Light
    {
        public:
            Light( Vector3 intensity, std::string name)
                : m_intensity(intensity), m_name(name) {}
            ~Light() = default;
        private:
            Vector3 m_intensity; // The intensity of the light (RGB)
            std::string m_name;
    };
    
}

#endif