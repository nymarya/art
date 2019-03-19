#include "../include/vector3.h"

art::Vector3::Vector3(component component1, component component2, component component3)
{
    m_components[0] = component1;
    m_components[1] = component2;
    m_components[2] = component3;
}

/////////////////
/// Accessors ///
/////////////////

/**
 * @brief Get x coordinate.
 */
component art::Vector3::x() const
{
    return m_components[COORDINATES::X];
}
/**
 * @brief Get y coordinate.
 */
component art::Vector3::y() const
{
    return m_components[COORDINATES::Y];
}
/**
 * @brief Get z coordinate.
 */
component art::Vector3::z() const
{
    return m_components[COORDINATES::Z];
}
/**
 * @brief Get red intensity.
 */
component art::Vector3::r() const {
    return m_components[RGB::RED]}
/**
 * @brief Get green intensity.
 */
component art::Vector3::g() const
{
    return m_components[RGB::GREEN];
}
/**
 * @brief Get blue intensity.
 */
component art::Vector3::b() const
{
    return m_components[RGB::BLUE];
}

/**
 * @brief Override operator for unitary plus.
 */
const art::Vector3 &art::Vector3::operator+() const
{
    return *this;
}

/**
 * @brief Override operator for unary minus.
 */
art::Vector3 art::Vector3::operator-() const
{
    return Vector3(-m_components[0], -m_components[1], -m_components[2]);
}

/**
 * @brief Override operator for sum with another
 * vector.
 */
art::Vector3 &art::Vector3::operator+=(const Vector3 &v2)
{
    m_components[0] += v2[0];
    m_components[1] += v2[1];
    m_components[2] += v2[2];
    return *this;
}

/**
 * @brief Override operator for subtraction with another
 * vector.
 */
art::Vector3 & art::Vector3::operator-=(const Vector3 &v2){
    m_components[0] -= v2[0];
    m_components[1] -= v2[1];
    m_components[2] -= v2[2];

    return *this;
}

/**
 * @brief Override operator for multiplication with another
 * vector. 
 */
art::Vector3 &art::Vector3::operator*=(const Vector3 &v2){
    m_components[0] *= v2[0];
    m_components[1] *= v2[1];
    m_components[2] *= v2[2];

    return *this;
}

/**
 * @brief Override operator for division by another
 * vector.
 */
art::Vector3 &art::Vector3::operator/=(const Vector3 &v2){
    m_components[0] /= v2[0];
    m_components[1] /= v2[1];
    m_components[2] /= v2[2];

    return *this;
}

/**
 * @brief Override operator for multiplication with component.
 */
art::Vector3 &art::Vector3::operator*=(const component t){
    m_components[0] *= t;
    m_components[1] *= t;
    m_components[2] *= t;

    return *this;
}

/**
 * @brief Override operator for division by component.
 */
art::Vector3 &art::Vector3::operator/=(const component t){
    m_components[0] /= t;
    m_components[1] /= t;
    m_components[2] /= t;

    return *this;
}

/**
 * @brief Access element.
 */
component art::Vector3::operator[](int i) const{
    return m_components[i];
}

/**
 * @brief Access element and return reference to it.
 */
component &art::Vector3::operator[](int i)
{
    return m_components[i];
}