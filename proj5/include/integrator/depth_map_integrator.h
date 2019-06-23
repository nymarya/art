#ifndef _depth_int_h_
#define _deptsh_int_h_

#include "sample_integrator.h"
#include "../common.h";

#include <cmath>

namespace art{
    /**
     * @brief This integrator produces a gray scale image representing the depth map 
     * of the scene, by normalizing the hit value and using this value to 
     * linearly interpolate a color between white and black.
     * 
     */
    class DepthMapIntegrator : public SampleIntegrator
    {
    
        public:
        DepthMapIntegrator(std::shared_ptr<Camera> camera, 
                               std::shared_ptr<art::Sampler> sampler,
                               Vector3 farcolor, Vector3 nearcolor)
            :SampleIntegrator(camera, sampler), m_far_color(farcolor),
            m_near_color(nearcolor){}

            DepthMapIntegrator(std::shared_ptr<Camera> camera, 
                               std::shared_ptr<art::Sampler> sampler,
                               Vector3 farcolor, Vector3 nearcolor,
                               float min, float max)
            :SampleIntegrator(camera, sampler), m_tMin(min), m_tMax(max),
            m_far_color(farcolor), m_near_color(nearcolor){}

            ~DepthMapIntegrator() = default;

            void preprocess( const Scene& scene, Sampler& sampler ) override;
            Vector3 Li( const Ray& ray, const Scene& scene, const Sampler& sampler ) const;

        private:
            // tMin and tMax are initialized in a way that the 
            // 'preprocess' step will adjust both.
            float m_tMin {std::numeric_limits<float>::max()};
            float m_tMax {std::numeric_limits<float>::min()};

            Vector3 m_far_color, m_near_color;
            bool m_fixed_t {false}; // parameter that defines if the tMin and tMax will be passed to the class
    };
    
    
}

#endif