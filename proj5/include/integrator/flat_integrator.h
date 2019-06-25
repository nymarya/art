#ifndef _fi_h_
#define _fi_h_

#include "../ray.h"
#include "sample_integrator.h"
#include "sampler.h"
#include "../scene.h"
#include "../surface_interaction.h"

namespace art{

    class FlatIntegrator : public SampleIntegrator
    {
    private:
        /* data */
        public:
            FlatIntegrator(std::shared_ptr<Camera> camera, 
                std::shared_ptr<art::Sampler> sampler)
            :SampleIntegrator(camera, sampler){}

            ~FlatIntegrator() = default;

            Vector3 Li( const Ray& ray, const Scene& scene, const Sampler& sampler ) const;
            void preprocess( const Scene& scene, Sampler& sampler )  override
            {
                //stub
                scene.stub();
                sampler.stub();
            }

    };
    
}

#endif