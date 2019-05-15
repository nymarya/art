#ifndef _agg_primitive_h_
#define _agg_primitive_h_

#include <memory>
#include "primitive.h"
#include <vector>

namespace art{
    /**
     * @brief Class that aggregates multiple primitives
     * in order to facilitate the processing.
     */
    class AggregatePrimitive
    { 
        public:
            /**
             * @brief Instatiate the new aggregate of primitive based on
             * a list of primitives.
             */ 
            AggregatePrimitive(std::vector<std::shared_ptr<Primitive>> primitives);
            ~AggregatePrimitive();

        private:
            // List of primitives
            std::vector<std::shared_ptr<Primitive>> m_primitives;
    };
    
}

#endif