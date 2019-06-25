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
        private:
            Vector3 m_position; // The position of the light (x y z)
    };
    
}

#endif