#include "../../include/material/blinn_material.h"

/**
 * @brief Get the ambient coefficient
 * 
 * @return Vector3 
 */
art::Vector3 ka();

/**
 * @brief Set the ambient coefficient.
 * 
 * @param ka 
 */
void ka(art::Vector3 ka);

/**
 * @brief Get the diffuse coefficient
 * 
 * @return Vector3 
 */
art::Vector3 kd();

/**
 * @brief Set the diffuse coefficient.
 * 
 * @param kd 
 */
void kd(art::Vector3 kd);

/**
 * @brief Get the specular coefficient.
 * 
 * @return Vector3 
 */
art::Vector3 s();

/**
 * @brief Set the specular coefficient.
 * 
 * @param s 
 */
void s(art::Vector3 s);

/**
 * @brief Get glossiness exponent.
 * 
 * @return real_t 
 */
real_t g();

/**
 * @brief Set glossiness exponent
 * 
 */
void g( real_t g );