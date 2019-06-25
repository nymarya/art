#ifndef _normal_int_h_
#define _normal_int_h_

#include "sample_integrator.h"

namespace art{

    /**
     * @brief The color of a hit is determined by making the normal 
     * at the hit point have length 1, and treating its coordinate 
     * values as RGB color.
     */
    class NormalMapIntegrator : public SampleIntegrator
    {
        private:
            /* data */
        public:
            NormalMapIntegrator(std::shared_ptr<Camera> camera, 
                                std::shared_ptr<art::Sampler> sampler)
                                :SampleIntegrator(camera, sampler){}
            ~NormalMapIntegrator() = default;

            Vector3 Li( const Ray& ray, const Scene& scene, const Sampler& sampler ) const;
            void preprocess( const Scene& scene, Sampler& sampler )  override{
                //stub
                scene.stub();
                sampler.stub();
            }
    };
    
}

#endif