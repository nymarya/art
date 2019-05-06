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
        FlatIntegrator(/* args */);
        ~FlatIntegrator();

        Color Li(const Ray& ray, const Scene& scene, Sampler& sampler);
    };
    
}

#endif