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
    Point3 origin = m_isect_one.p() + m_isect_one.n().normalize() * 0.001f;
    Vector3 v = m_isect_two.p() - origin;

    // Create
    std::shared_ptr<Ray> r (new Ray(origin, v));
    r->tMax(1.0);
    return  r;
}