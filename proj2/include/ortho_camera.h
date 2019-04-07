#ifndef _ortho_h_
#define _ortho_h_

#include "camera.h"

namespace art{
    /**
     * @brief Class representing a orthographic camera.
     */
    class OrthoCamera : public Camera
    {
        public:
            OrthoCamera(const size_t width, const size_t height);
            ~OrthoCamera() = default;

            /**
             * @brief Generate a ray with passing through (x,y).
             */
            Ray generate_ray(int x, int y);

        private:
            /*data*/
    };

    
}

#endif