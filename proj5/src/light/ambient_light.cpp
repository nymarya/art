#include "../../include/light/ambient_light.h"

/**
 * @brief Calculates the contribution of the light
 */
art::Vector3 art::AmbientLight::Li(const SurfaceInteraction &isect, Vector3 *wi,
                            VisibilityTester *vt)
{
    return intensity();
}