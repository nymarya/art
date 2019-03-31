#include "../include/vector3.h"

art::Vector3::Vector3(component_t component1, component_t component2, component_t component3)
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
component_t art::Vector3::x() const
{
    return m_components[COORDINATES::X];
}
/**
 * @brief Get y coordinate.
 */
component_t art::Vector3::y() const
{
    return m_components[COORDINATES::Y];
}
/**
 * @brief Get z coordinate.
 */
component_t art::Vector3::z() const
{
    return m_components[COORDINATES::Z];
}
/**
 * @brief Get red intensity.
 */
component_t art::Vector3::r() const
{
    return m_components[RGB::RED];
}
/**
 * @brief Get green intensity.
 */
component_t art::Vector3::g() const
{
    return m_components[RGB::GREEN];
}
/**
 * @brief Get blue intensity.
 */
component_t art::Vector3::b() const
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
art::Vector3 &art::Vector3::operator-=(const Vector3 &v2)
{
    m_components[0] -= v2[0];
    m_components[1] -= v2[1];
    m_components[2] -= v2[2];

    return *this;
}

/**
 * @brief Override operator for multiplication with another
 * vector. 
 */
art::Vector3 &art::Vector3::operator*=(const Vector3 &v2)
{
    m_components[0] *= v2[0];
    m_components[1] *= v2[1];
    m_components[2] *= v2[2];

    return *this;
}

/**
 * @brief Override operator for division by another
 * vector.
 */
art::Vector3 &art::Vector3::operator/=(const Vector3 &v2)
{
    m_components[0] /= v2[0];
    m_components[1] /= v2[1];
    m_components[2] /= v2[2];

    return *this;
}

/**
 * @brief Override operator for multiplication with component.
 */
art::Vector3 &art::Vector3::operator*=(const component_t t)
{
    m_components[0] *= t;
    m_components[1] *= t;
    m_components[2] *= t;

    return *this;
}

/**
 * @brief Override operator for division by component.
 */
art::Vector3 &art::Vector3::operator/=(const component_t t)
{
    m_components[0] /= t;
    m_components[1] /= t;
    m_components[2] /= t;

    return *this;
}

/**
 * @brief Access element.
 */
component_t art::Vector3::operator[](int i) const
{
    return m_components[i];
}

/**
 * @brief Access element and return reference to it.
 */
component_t &art::Vector3::operator[](int i)
{
    return m_components[i];
}

/**
 * @brief Override operator for sum between vectors.
 */
art::Vector3 art::Vector3::operator+(const art::Vector3 &v2)
{
    return art::Vector3(m_components[0] + v2[0], m_components[1] + v2[1], m_components[2] + v2[2]);
}

/**
 * @brief Override operator for difference between vectors.
 */
art::Vector3 art::Vector3::operator-(const art::Vector3 &v2)
{
    return art::Vector3(m_components[0] - v2[0], m_components[1] - v2[1], m_components[2] - v2[2]);
}

/**
 * @brief Override operator for multiplication between vectors.
 */
art::Vector3 operator*(const art::Vector3 &v1, const art::Vector3 &v2)
{
    return art::Vector3(v1[0] * v2[0], v1[1] * v2[1], v1[2] * v2[2]);
}

/**
 * @brief Override operator for division between vectors.
 */
art::Vector3 operator/(const art::Vector3 &v1, const art::Vector3 &v2)
{
    return art::Vector3(v1[0] / v2[0], v1[1] / v2[1], v1[2] / v2[2]);
}

/**
 * @brief Override operator for multiplication between component_t and vector.
 */
art::Vector3 operator*(component_t t, const art::Vector3 &v)
{
    return art::Vector3(t * v[0], t * v[1], t * v[2]);
}

/**
 * @brief Override operator for division between vector and scalar.
 */
art::Vector3 operator/(art::Vector3 v, component_t t)
{
    return art::Vector3(v[0] / t, v[1] / t, v[2] / t);
}

/**
 * @brief Override operator for multiplication between vector and scalar.
 */
art::Vector3 art::Vector3::operator*(component_t t)
{
    return art::Vector3(t * m_components[0], t * m_components[1], t * m_components[2]);
}

/**
 * @brief Override operator for dot product between vectors.
 */
component_t dot(const art::Vector3 &v1, const art::Vector3 &v2)
{
    return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

/**
 * @brief Override operator for product between vectors.
 */
art::Vector3 cross(const art::Vector3 &v1, const art::Vector3 &v2)
{
    return art::Vector3((v1[1] * v2[2] - v1[2] * v2[1]),
                        (-(v1[0] * v2[2] - v1[2] * v2[0])),
                        (v1[0] * v2[1] - v1[1] * v2[0]));
}