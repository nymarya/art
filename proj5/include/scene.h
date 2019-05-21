#ifndef _scene_h_
#define _scene_h_

#include <iostream>
#include <memory>
#include <vector>

#include "background.h"
//#include "light.h"
#include "primitive/primitive.h"
#include "ray.h"
#include "surface_interaction.h"

namespace art{
    class Scene {
        //=== Public data
        public:
            //std::vector<std::shared_ptr<Light>> lights; // list of lights
            std::shared_ptr< Background > m_background; // The background object.
        private:
            std::shared_ptr<Primitive> m_aggregate; // The scene graph of objects, acceleration structure.

        //=== Public interface
        public:
            Scene( std::shared_ptr<Primitive> ag, std::shared_ptr<Background> bkg )
                :m_background{bkg}, m_aggregate{ag}
                {/* empty */}
            /// Determines the intersection info; return true if there is an intersection.
            bool intersect( const Ray& r, SurfaceInteraction *isect ) const
            {
                return m_aggregate->intersect(r, isect);
            }
            /*! A faster version that only determines whether there is an intersection or not;
            * it doesn't calculate the intersection info.
            */
            bool intersect_p( const Ray& r ) const
            {
                return m_aggregate->intersect_p(r);
            }
    };
}

#endif