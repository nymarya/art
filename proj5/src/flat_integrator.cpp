#include "../include/integrator/flat_integrator.h"
#include "../include/material/flat_material.h"

/**
 * @Override
 * 
 */
art::Vector3 art::FlatIntegrator::Li(const Ray& ray, const Scene& scene, const Sampler& sampler) const
{
    std::cout << "Li 1\n";
    Vector3 L((component_t) 0,0,0); // The radiance
    // Find closest ray intersection or return background radiance.
    SurfaceInteraction isect; 
    std::cout << "Li 2\n"; 
    if (!scene.intersect(ray, &isect)) {
        std::cout << "Li 3\n";
        // This might be just:
        const size_t h = camera->film()->height();
        auto w = camera->film()->width();

        float x = float(ray.x())/float(w);
        float y = float(ray.y())/float(h);
        std::cout << "Li 4\n";
        L = scene.m_background->color(x, y);
    }
    else {
        // Some form of determining the incoming radiance at the ray's origin.
        // For this integrator, it might just be:
        // Polymorphism in action.
        std::cout << "Li 5\n";
        if ( isect.primitive() != nullptr) 
            std::cout << "Li 6.5\n";
        FlatMaterial *fm = dynamic_cast< FlatMaterial *>( isect.primitive()->get_material() );
        std::cout << "Li 6\n";

        // Assign diffuse color to L.
        L = fm->diffuse(); // Call a method present only in FlatMaterial.
        std::cout << "Li 7\n";
    }
    return L;
}