#include "integrator/flat_integrator.h"

/**
 * @Override
 * 
 */
art::Color art::FlatIntegrator::Li(const Ray& ray, const Scene& scene, Sampler& sampler)
{
    Color L((component_t) 0,0,0); // The radiance
    // Find closest ray intersection or return background radiance.
    SurfaceInteraction isect;  
    if (!scene.intersect(ray, &isect)) {
        // This might be just:
        L = scene.background.sample(r);
    }
    else {
        // Some form of determining the incoming radiance at the ray's origin.
        // For this integrator, it might just be:
        // Polymorphism in action.
        FlatMaterial *fm = dynamic_cast< FlatMaterial *>( iscet.primitive->get_material() );
        // Assign diffuse color to L.
        L = fm->kd(); // Call a method present only in FlatMaterial.
    }
    return L;
}