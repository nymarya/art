#ifndef _blinn_integrator_h_
#define _blinn_integrator_h_

#include "sample_integrator.h"

namespace art{
    class BlinnPhongIntegrator : public SampleIntegrator
    {
        public:
            BlinnPhongIntegrator(/* args */);
            ~BlinnPhongIntegrator();
        private:
            /* data */
    };

    
}

#endif