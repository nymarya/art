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
        // Variable that keeps the intensity
        // of the ambient light
        Vector3 ambient_contrib = Vector3(0.0, 0.0, 0.0);

        //Evaluate shading model and set pixel to that color.
        BlinnMaterial *fm = dynamic_cast< BlinnMaterial *>( isect.primitive()->get_material() );

        for (auto light : scene.lights()) 
        {
            //sstd::cout << "lights\n";
            if (light->is_ambient())
            {
                // Compute  the surface’s ambient coefficient, or “ambient color,” and the
                // ambient light intensity.
                ambient_contrib = fm->ka().mult(light->intensity());
            } 
            else 
            {
                Vector3 wi;
                VisibilityTester vt;
                // Compute n
                Vector3 n = isect.n();

                // Evaluate shading model and set pixel to that color
                auto i = light->Li(isect, &wi, &vt); //intensity
                // Compute the equation equivalent v + l 
                // in the Blinn-Phong model
                auto h = isect.wo().normalize() + wi;
                h /= h.normalize(); // Make unit vector

                if (vt.unoccluded(scene)){
                    // Use the Blinn-Phong model equation
                    L += fm->kd().mult(i) * fmax(0.0, h * wi ) ;
                    L += fm->s().mult(i) * pow(fmax(0.0, h * h ), fm->g());
                }
            }

        }
        
        L = (L+ambient_contrib) * 255.0;
    }
    sampler.stub();
    
        return {fmin(255.0f, L.r()), fmin(255.0f, L.g()), fmin(255.0f, L.b())};
}