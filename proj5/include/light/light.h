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
            Light( Vector3 intensity, std::string name, bool ambient)
                : m_intensity(intensity), m_name(name), m_ambient(ambient) {}
            ~Light() = default;

            /**
             * @brief Checks whether the light is ambient.
             * 
             * @return true 
             * @return false 
             */
            bool is_ambient() {return m_ambient; }

            Vector3 intensity() {return m_intensity; }

            Vector3 Li( const SurfaceInteraction &isect, Vector3 *wi, VisibilityTester *vt);
        private:
            Vector3 m_intensity; // The intensity of the light (RGB)
            std::string m_name;
            bool m_ambient {false};
    };
    
}

#endif