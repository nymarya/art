#ifndef _fi_h_
#define _fi_h_

#include "ray.h"
#include "sample_integrator.h"
#include "sampler.h"
#include "scene.h"

namespace art{

    class FlatIntegrator : public SampleIntegrator
    {
    private:
        /* data */
        public:
            FlatIntegrator(std::shared_ptr<Camera> camera, std::shared_ptr<art::Sampler> sampler);
            ~FlatIntegrator();

            Color Li( const Ray& ray, const Scene& scene, const Sampler& sampler ) const;

    };
    
}

#endif