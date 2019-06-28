#include "../../include/integrator/blinn_integrator.h"

art::Vector3 art::BlinnPhongIntegrator::Li( const Ray& ray, 
                                        const Scene& scene, 
                                        const Sampler& sampler ) const
{
    Vector3 L((component_t) 0,0,0); // The radiance
    // Find closest ray intersection or return background radiance.
    SurfaceInteraction isect; 
    if (!scene.intersect(ray, &isect)) {
        // If no object is found, get pixel from background
        
        float u,v = 0.0;
        std::tie(u, v) = ray.uv();
        L = scene.m_background->color(u, v);
    }
    else {
        Vector3 wi;
        VisibilityTester vt;
        
        // Compute n
        auto n = isect.n();

        //Evaluate shading model and set pixel to that color.
        BlinnMaterial *fm = dynamic_cast< BlinnMaterial *>( isect.primitive()->get_material() );

        for (auto light : scene.lights()) 
        {
            if (light->is_ambient())
            {
                L += light->intensity();
            } 
            else 
            {
                auto Ii = light->Li(isect, &wi, &vt);
                auto n = isect.n;

                auto wo = isect.wo;
                auto h = wo + wi;
                h.make_unit_vector();

                if (vt.unoccluded(scene)){
                    L += fm->kd().cross(Ii).cross( fmax(0.0, n * wi) );
                    L += fm->ks() * Ii * pow(fmax(0.0, dot(n, h)), gloss);
                }
            }

        }
        // Use lambertian shading model to
        // 
        L = fm->kd();
    }
    sampler.stub();
    return L;
}