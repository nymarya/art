#include "../include/ortho_camera.h"

art::OrthoCamera::OrthoCamera(const size_t width, const size_t height)
:Camera(width, height)
{/*empty*/}

/**
 * @brief Generate a ray with passing through (x,y).
 */
art::Ray art::OrthoCamera::generate_ray(int x, int y){

}