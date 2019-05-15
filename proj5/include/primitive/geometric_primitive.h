#ifndef _geometric_primitive_h_
#define _geometric_primitive_h_

#include <memory>
#include "../shape/shape.h"
#include "primitive.h"

namespace art{
    class GeometricPrimitive : public Primitive
    {
        public:
            GeometricPrimitive(/* args */);
            ~GeometricPrimitive();

        private:
            std::shared_ptr<Shape> m_shape;
    };
    
}

#endif