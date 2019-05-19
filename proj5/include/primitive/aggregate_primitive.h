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
    class AggregatePrimitive : public Primitive
    { 
        public:
            /**
             * @brief Instatiate the new aggregate of primitive based on
             * a list of primitives.
             */ 
            AggregatePrimitive(std::vector<std::shared_ptr<Primitive>> primitives);
            ~AggregatePrimitive();

            /**
             * @brief Check if ray intersect with surface of any shape.
             * 
             * @param r 
             * @return true 
             * @return false 
             */
            bool intersect( const Ray& r, SurfaceInteraction *) const;
            
            /**
             * @brief Simpler & faster version of intersection that only return true/false.
             * It does not compute the hit point information.
             * 
             * @param r 
             * @return true 
             * @return false 
             */
            bool intersect_p( const Ray& r ) const;

        private:
            // List of primitives
            std::vector<std::shared_ptr<Primitive>> m_primitives;
    };
    
}

#endif