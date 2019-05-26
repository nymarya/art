 #include "../include/camera/perspective_camera.h"
 
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
    // Find the half-height and half-width
    auto hh = tan( (m_fovy*RADIANS) /2.0)*m_fdistance;
    auto hw = m_aspect * hh;
    
    float l = -hw; float r= hw;
    float b = -hh; float t = hh; 

    // Determine the camera orthonormal frame
    Vector3 gaze = m_target - m_position; 
    Vector3 w = (-gaze).normalize();
    // right-hand orientation
    Vector3 u = m_up.cross(w).normalize(); 
    Vector3 v = w.cross(u).normalize();

    // Mapping Pixels to Screen Space
    auto u_scalar = l + (r - l)*(x * width() + 0.5)/width();
    auto v_scalar = b + (t - b)*(y * height() + 0.5)/height();
    std::cout << "u: " << u_scalar << " v: " << v_scalar;

    auto direction = (-w * m_fdistance) + (u * u_scalar) + (v * v_scalar);
    auto origin = m_position ;

    return Ray(origin, direction.normalize());
}

art::Ray art::PerspectiveCamera::generate_ray(float x, float y){
   // Find the half-height and half-width
    auto hh = tan( (m_fovy*RADIANS) /2.0)*m_fdistance;
    auto hw = m_aspect * hh;
    
    float l = -hw; float r= hw;
    float b = -hh; float t = hh; 

    // Determine the camera orthonormal frame
    Vector3 gaze = m_target - m_position; 
    Vector3 w = (-gaze).normalize();
    // right-hand orientation
    Vector3 u = m_up.cross(w).normalize(); 
    Vector3 v = w.cross(u).normalize();

    // Mapping Pixels to Screen Space
    auto u_scalar = l + (r - l)*(x * width() + 0.5)/width();
    auto v_scalar = b + (t - b)*(y * height() + 0.5)/height();
    std::cout << "x: " << x << " y: " << y << "\n";
    std::cout << "u: " << u_scalar << " v: " << v_scalar <<"\n";

    auto direction = (-w * m_fdistance) + (u * u_scalar) + (v * v_scalar);
    auto origin = m_position ;

    return Ray(origin, direction.normalize());
}