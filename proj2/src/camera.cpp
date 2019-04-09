#include "../include/camera.h"

art::Camera::Camera(const size_t width, const size_t height,
Vector3 position, Vector3 target, Vector3 up)
:m_width( width), m_height (height), m_position(position),
m_target(target), m_up(up)
{/*empty*/}