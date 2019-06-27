#include "../../include/material/blinn_material.h"

/**
 * @brief Get the ambient coefficient
 * 
 * @return Vector3 
 */
art::Vector3 art::BlinnMaterial::ka()
{
    return m_ka;
}

/**
 * @brief Set the ambient coefficient.
 * 
 * @param ka 
 */
void art::BlinnMaterial::ka(art::Vector3 ka)
{
    m_ka = ka;
}

/**
 * @brief Get the diffuse coefficient
 * 
 * @return Vector3 
 */
art::Vector3 art::BlinnMaterial::kd()
{
    return m_kd;
}

/**
 * @brief Set the diffuse coefficient.
 * 
 * @param kd 
 */
void art::BlinnMaterial::kd(art::Vector3 kd)
{
    m_kd = kd;
}

/**
 * @brief Get the specular coefficient.
 * 
 * @return Vector3 
 */
art::Vector3 art::BlinnMaterial::s()
{
    return m_s;
}

/**
 * @brief Set the specular coefficient.
 * 
 * @param s 
 */
void art::BlinnMaterial::s(art::Vector3 s)
{
    m_s = s;
}

/**
 * @brief Get glossiness exponent.
 * 
 * @return real_t 
 */
real_t art::BlinnMaterial::g()
{
    return m_g;
}

/**
 * @brief Set glossiness exponent
 * 
 */
void art::BlinnMaterial::g( real_t g )
{
    m_g = g;
}