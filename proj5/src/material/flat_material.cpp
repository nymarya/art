#include "../../include/material/flat_material.h"

art::FlatMaterial::FlatMaterial(component_t r, component_t g, component_t b, std::string name)
:m_rgb(art::Vector3(r, g, b)), Material(name)
{

}

/**
 * @brief Get diffuse material/color.
 * 
 * @return Vector3 
 */
art::Vector3 art::FlatMaterial::diffuse()
{
    return m_rgb;
}