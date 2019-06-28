#ifndef _visibility_tester_h_
#define _visibility_tester_h_

#include "../scene.h"
#include "../surface_interaction.h"
#include "../ray.h"

namespace art 
{
    /**
     * @brief This auxiliary class testes wheter a shadow
     * ray suffered a occlusion.
     */
    class VisibilityTester
    {
    
        public:
            VisibilityTester();
            VisibilityTester(const SurfaceInteraction &s1, const SurfaceInteraction &s2)
                : m_isect_one{s1}, m_isect_two{ s2 } {}

            ~VisibilityTester() = default;

            /**
             * @brief  Casts a shadow ray and check if it suffered
             * occlusion. 
             * 
             * @param scene     
             * @return true     
             * @return false    
             */
            bool unoccluded(const Scene &scene);

        private:
            /* data */
            SurfaceInteraction m_isect_one;
            SurfaceInteraction m_isect_two;

            /**
             * @brief   This is a helper function to cast a ray from p0 to p1
             * 
             * @return std::shared_ptr<Ray> 
             */
            std::shared_ptr<Ray> raycaster() const;
    };
    
}

#endif