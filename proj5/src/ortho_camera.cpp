#include "../include/camera/ortho_camera.h"

art::OrthoCamera::OrthoCamera(const size_t width, const size_t height, 
Vector3 position, Vector3 target, Vector3 up, int * vdim)
:Camera(width, height, position, target, up), m_vdim(vdim)
{/*empty*/}

/**
 * @brief Generate a ray with passing through (x,y).
 */
art::Ray art::OrthoCamera::generate_ray(int x, int y){
    // recover screen space 
    auto l = m_vdim[0];
    auto r = m_vdim[1];
    auto b = m_vdim[2];
    auto t = m_vdim[3];

    // Mapping Pixels to Screen Space
    auto u_scalar = l + (r - l)*(x + 0.5)/width();
    auto v_scalar = b + (t - b)*(y + 0.5)/height();

    // Determine the camera orthonormal frame
    Vector3 gaze = m_target - m_position; 
    Vector3 w = (-gaze).normalize();
    // right-hand orientation
    Vector3 u = m_up.cross(w).normalize(); 
    Vector3 v = w.cross(u).normalize() ;
    Point3 e = m_position;

    // Determine the origin of the frame, i.e. the lower left corner of the view
    auto llc =  e + w * b + u * l;

    // Determine the (full length) vectors along the vertical and horizontal
    //  dimensions
    auto vph = u * (2 * (r - l));
    auto vpv = v * (2 * (t - b));

    auto direction = -w;
    auto origin = e + u*u_scalar + v * v_scalar;

    return Ray(origin, direction);
}

/**
 * @brief Generate a ray with passing through (x,y)
 * with the view plane frame method.
 */
art::Ray art::OrthoCamera::generate_ray(float x, float y){
   // recover screen space 
    auto l = m_vdim[0];
    auto r = m_vdim[1];
    auto b = m_vdim[2];
    auto t = m_vdim[3];

    // Determine the camera orthonormal frame
    Vector3 gaze = m_target - m_position; 
    Vector3 w = (-gaze).normalize();
    // right-hand orientation
    Vector3 u = m_up.cross(w).normalize(); 
    Vector3 v = w.cross(u).normalize() ;
    Point3 e = m_position;

    // Determine the origin of the frame, i.e. the lower left corner of the view
    auto llc =  e + w * b + u * l;

    // Determine the (full length) vectors along the vertical and horizontal
    //  dimensions
    auto vph = u * (2 * (r - l));
    auto vpv = v * (2 * (t - b));

    auto direction = -w;
    auto origin = llc + vph*x + vpv * y;

    return Ray(origin, direction);
}