#include "../include/camera/camera.h"

art::Camera::Camera(const size_t width, const size_t height,
Vector3 position, Vector3 target, Vector3 up)
:m_width( width), m_height (height), m_position(position),
m_target(target), m_up(up)
{/*empty*/}

 /**
 * @brief Get width.
 */
size_t art::Camera::width() const
{
    return m_width;
}

/**
 * @brief Get height.
 */
size_t art::Camera::height() const
{
    return m_height;
}

 /**
 * @brief Get film.
 */
std::unique_ptr<art::Buffer> art::Camera::film()
{
    return std::make_unique<Buffer>(m_film.get());
}