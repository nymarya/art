#include "../../include/light/visibility_tester.h"

/**
 * @brief Casts a shadow ray and check if it suffered
 * occlusion. 
 */
bool art::VisibilityTester::unoccluded(const art::Scene &scene)
{
    auto newRay = *raycaster().get();
    return !scene.intersect_p(newRay);
}

/**
 * @brief This is a helper function to cast a ray from isect_one to isect_two
 */
std::shared_ptr<art::Ray> art::VisibilityTester::raycaster() const
{
    // Get the direction of the new ray
    // Destiny - origin
    Vector3 v = m_isect_two.p() - m_isect_one.p();

    // Create
    std::shared_ptr<Ray> r (new Ray(m_isect_one.p(), v));
    r->tMax(1);
    return  r;
}