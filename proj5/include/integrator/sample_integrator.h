#ifndef _sampler_int_h_
#define _sampler_int_h_

#include "camera/camera.h"
#include "integrator.h"
#include "../geometry/point2d.h"
#include "../geometry/vector3.h"
#include "../sampler.h"

namespace art{
    class SampleIntegrator : public Integrator {
    //=== Public interface
    public:
        ~SampleIntegrator();
        SampleIntegrator( std::shared_ptr<const Camera> cam,
                          std::shared_ptr<Sampler> sampler)
            : camera{cam}, sampler{sampler}{};

        virtual Vector3 Li( const Ray& ray, const Scene& scene,
                const Sampler& sampler ) const = 0;
        /**
         * The main loop that traverse the pixels and
         * creates an image. */
        void render( const Scene& scene );
        void preprocess( const Scene& scene ){}

    protected:
        std::shared_ptr<const Camera> camera;
    private:
        std::shared_ptr<Sampler> sampler;
};
}

#endif