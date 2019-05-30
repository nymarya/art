#include "../include/integrator/flat_integrator.h"
#include "../include/material/flat_material.h"

#include <tuple>

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
        // If no object is found, get pixel from background
        const size_t h = m_camera->film()->height();
        auto w = m_camera->film()->width();

        float x = float(ray.x())/float(w);
        float y = float(ray.y())/float(h);
        float u,v = 0.0;
        std::tie(u, v) = ray.uv();
        std::cout << "Li 4\n";
        L = scene.m_background->color(u, v);
    }
    else {
        // Some form of determining the incoming radiance at the ray's origin.
        // For this integrator, it might just be:
        // Polymorphism in action.
        FlatMaterial *fm = dynamic_cast< FlatMaterial *>( isect.primitive()->get_material() );

        // Assign diffuse color to L.
        L = fm->diffuse(); // Call a method present only in FlatMaterial.
        std::cout << fm->name() << std::endl;
    }
    return L;
}