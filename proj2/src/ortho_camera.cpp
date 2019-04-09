#include "../include/ortho_camera.h"

art::OrthoCamera::OrthoCamera(const size_t width, const size_t height, 
Vector3 position, Vector3 target, Vector3 up, int * vdim)
:Camera(width, height, position, target, up), m_vdim(vdim)
{/*empty*/}

/**
 * @brief Generate a ray with passing through (x,y).
 */
art::Ray art::OrthoCamera::generate_ray(int x, int y){

}