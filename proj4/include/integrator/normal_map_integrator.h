#ifndef _normal_int_h_
#define _normal_int_h_

#include "sample_integrator.h"

namespace art{

    class NormalMapIntegrator : public SampleIntegrator
    {
        private:
            /* data */
        public:
            NormalMapIntegrator(/* args */);
            ~NormalMapIntegrator();
    };
    
}

#endif