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
            OrthoCamera(const size_t width, const size_t height, 
            Vector3 position, Vector3 target, Vector3 up, int *vdim );
            ~OrthoCamera() = default;

            /**
             * @brief Generate a ray with passing through (x,y).
             */
            Ray generate_ray(int x, int y);

        private:
            /*data*/
            int* m_vdim;
    };

    
}

#endif