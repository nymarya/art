#ifndef _perspective_h_
#define _perspective_h_

#include "camera.h"

#include <math.h>

#define RADIANS 0.01745329252    // value of a degree in radians

namespace art{
    /**
     * @brief Class representing a perspective camera.
     */
    class PerspectiveCamera : public Camera
    {
        public:
            PerspectiveCamera(const size_t width, const size_t height, 
                            Vector3 position, Vector3 target, Vector3 up,
                            component_t fovy, component_t aspect,
                            component_t fdistance);
            ~PerspectiveCamera();

            /**
             * @brief Generate a ray with passing through (x,y).
             */
            Ray generate_ray(int x, int y);

            /**
             * @brief Generate a ray with passing through (x,y)
             * with the view plane frame method.
             */
            Ray generate_ray(float x, float y);
        private:
            /* data */
            component_t m_fovy , m_aspect, m_fdistance; 
    };
    
}

#endif