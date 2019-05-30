#include "../../include/material/flat_material.h"

art::FlatMaterial::FlatMaterial(component_t r, component_t g, component_t b, std::string name)
:m_rgb(art::Vector3(r/255.0, g/255.0, b/255.0)), Material(name)
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