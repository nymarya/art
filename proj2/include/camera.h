#ifndef _camera_h_
#define _camera_h_

#include <iostream>

#include "ray.h"

namespace art{
    /**
     * @brief Virtual class that defines a camera model.
     */
    class Camera
    {
    public:
        Camera(const size_t width, const size_t height, Vector3 position, 
                Vector3 target, Vector3 up);
        ~Camera() = default;

        /**
         * @brief Generate a ray with passing through (x,y).
         */
        virtual Ray generate_ray(int x, int y) = 0;

    private:
        size_t m_width, m_height;

        Vector3 m_position, m_target, m_up;
    };
    
}


#endif