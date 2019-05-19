#include "../include/integrator/flat_integrator.h"

/**
 * @Override
 * 
 */
art::Color art::FlatIntegrator::Li(const Ray& ray, const Scene& scene, const Sampler& sampler) const
{
    Color L((component_t) 0,0,0); // The radiance
    // Find closest ray intersection or return background radiance.
    SurfaceInteraction isect;  
    if (!scene.intersect(ray, &isect)) {
        // This might be just:
        float _x = float(ray)/float(img_dim.x());
        float _y = float(ray.y)/float(img_dim.y());
        L = scene.m_background->color(ray);
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