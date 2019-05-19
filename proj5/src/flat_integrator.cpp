#include "../include/integrator/flat_integrator.h"
#include "../include/material/flat_material.h"

/**
 * @Override
 * 
 */
art::Vector3 art::FlatIntegrator::Li(const Ray& ray, const Scene& scene, const Sampler& sampler) const
{
    Vector3 L((component_t) 0,0,0); // The radiance
    // Find closest ray intersection or return background radiance.
    SurfaceInteraction isect;  
    if (!scene.intersect(ray, &isect)) {
        // This might be just:
        const size_t h = camera->film()->height();
        auto w = camera->film()->width();

        float x = float(ray.x())/float(w);
        float y = float(ray.y())/float(h);
        L = scene.m_background->color(x, y);
    }
    else {
        // Some form of determining the incoming radiance at the ray's origin.
        // For this integrator, it might just be:
        // Polymorphism in action.
        FlatMaterial *fm = dynamic_cast< FlatMaterial *>( isect.primitive()->get_material() );
        // Assign diffuse color to L.
        L = fm->diffuse(); // Call a method present only in FlatMaterial.
    }
    return L;
}