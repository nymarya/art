#ifndef _integrator_h_
#define _integrator_h_

#include <iostream>
#include "../scene.h"

namespace art{
    class Integrator {
        public:
            virtual ~Integrator() {};
            virtual void render( const Scene& scene ) =0;
    };
}

#endif