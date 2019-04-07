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
        Camera(const size_t width, const size_t height);
        ~Camera() = default;

        /**
         * @brief Generate a ray with passing through (x,y).
         */
        virtual Ray generate_ray(int x, int y) = 0;

    private:
        size_t m_width, m_height;
    };
    
}


#endif