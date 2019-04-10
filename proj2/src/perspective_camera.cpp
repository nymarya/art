 #include "../include/perspective_camera.h"
 
art::PerspectiveCamera::PerspectiveCamera(const size_t width, const size_t height,
Vector3 position, Vector3 target, Vector3 up, component_t fovy, component_t aspect,
component_t fdistance)
: Camera(width, height, position, target, up), m_fovy(fovy), 
m_aspect(aspect), m_fdistance(fdistance)
{/*empty*/}

/**
 * @brief Generate a ray with passing through (x,y).
 */
art::Ray art::PerspectiveCamera::generate_ray(int x, int y)
{
    
}