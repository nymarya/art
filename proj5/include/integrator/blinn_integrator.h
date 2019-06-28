#ifndef _blinn_integrator_h_
#define _blinn_integrator_h_

#include "sample_integrator.h"
#include "../material/blinn_material.h"
#include "../light/visibility_tester.h"

namespace art{
    /**
     * @brief This class implements a integrator for the 
     * Blinn-Phong reflection model, which aims to increase 
     * the scene realism.
     */
    class BlinnPhongIntegrator : public SampleIntegrator
    {
        public:
            BlinnPhongIntegrator(std::shared_ptr<Camera> camera, 
                                std::shared_ptr<art::Sampler> sampler)
                                :SampleIntegrator(camera, sampler){}
            ~BlinnPhongIntegrator() = default;

            Vector3 Li( const Ray& ray, const Scene& scene, const Sampler& sampler ) const override;
            void preprocess( const Scene& scene, Sampler& sampler )  override{
                //stub
                scene.stub();
                sampler.stub();
            }
        private:
            /* data */
    };

    
}

#endif