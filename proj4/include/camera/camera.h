#ifndef _camera_h_
#define _camera_h_

#include <iostream>

#include "buffer.h"
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

        /**
         * @brief Generate a ray with passing through (x,y).
         */
        virtual Ray generate_ray(component_t x, component_t y) = 0;

        /**
         * @brief Get width.
         */
        size_t width();

        /**
         * @brief Get height.
         */
        size_t height();

        /**
         * @brief Get film.
         */
        Buffer film();

    Vector3 m_position, m_target, m_up;
    private:
        size_t m_width, m_height;
        std::unique_ptr<Buffer> m_film;
        
    };
    
}


#endif