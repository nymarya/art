#include "../../include/integrator/normal_map_integrator.h"

art::Vector3 art::NormalMapIntegrator::Li(const Ray &ray, const Scene &scene,
                                         const Sampler &sampler) const
{
    Vector3 L((component_t)0, 0, 0); // The radiance
    // Find closest ray intersection or return background radiance.
    SurfaceInteraction isect;
    if (!scene.intersect(ray, &isect))
    {
        // If no object is found, get pixel from background
        // Color for a far point
        // If no object is found, get pixel from background
        
        float u,v = 0.0;
        std::tie(u, v) = ray.uv();
        L = scene.m_background->color(u, v);
    }
    else
    {

        // Get the normal at the hit point
        Vector3 n = isect.n().normalize();

        // Map the value to RGB using equation 
        // from Peter Shirley's Ray Tracing in one Weekend
        float r = (n.r() + 1.0f) * 0.5f;
        float g = (n.g() + 1.0f) * 0.5f;
        float b = (n.b() + 1.0f) * 0.5f;

        return Vector3{r, g, b};
    }
    sampler.stub();
    return L;
}