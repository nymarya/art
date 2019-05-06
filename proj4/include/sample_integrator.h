#ifndef _sampler_int_h_
#define _sampler_int_h_

#include "camera/camera.h"
#include "integrator.h"
#include "point2d.h"
#include "sampler.h"

namespace art{
    class SampleIntegrator : public Integrator {
    //=== Public interface
    public:
        virtual ~SampleIntegrator();
        SampleIntegrator( std::shared_ptr<const Camera> cam,
                          std::shared_ptr<Sampler> sampler)
            : camera{cam}, sampler{sampler}{};

        virtual Color Li( const Ray& ray, const Scene& scene,
                Sampler& sampler ) const = 0;
        virtual void render( const Scene& scene );
        virtual void preprocess( const Scene& scene );

    protected:
        std::shared_ptr<const Camera> camera;
    private:
        std::shared_ptr<Sampler> sampler;
};
}

#endif