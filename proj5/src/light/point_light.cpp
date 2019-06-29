#include "../../include/light/point_light.h"

/**
 * @brief Calculates the contribution of the light
 */
art::Vector3 art::PointLight::Li(const SurfaceInteraction &isect, Vector3 *wi,
                            VisibilityTester *vt)
{

    *wi = (m_position - isect.p()).normalize();

    auto s2 = SurfaceInteraction();
    s2.p(m_position);
    *vt = VisibilityTester(isect, s2);

    return intensity();
}