 #include "../include/perspective_camera.h"
 
art::PerspectiveCamera::PerspectiveCamera(const size_t width, const size_t height)
:Camera(width, height)
{/*empty*/}

/**
 * @brief Generate a ray with passing through (x,y).
 */
art::Ray art::PerspectiveCamera::generate_ray(int x, int y)
{

}