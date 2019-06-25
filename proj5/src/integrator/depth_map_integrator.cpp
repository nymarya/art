#include "../../include/integrator/depth_map_integrator.h"

void art::DepthMapIntegrator::preprocess(const Scene &scene, Sampler &sampler)
{
    std::cout << "pre\n";
    if (m_fixed_t)
        return;

    auto width = m_camera->film()->height();
    auto height = m_camera->film()->height();
    for (auto x = 0u; x < width; ++x)
    {
        for (auto y = 0u; y < height; ++y)
        {
            float _x = x / (float)width;
            float _y = y / (float)height;
            Ray ray = m_camera->generate_ray(_x, _y);
            SurfaceInteraction isect;
            if (scene.intersect(ray, &isect))
            {
                m_tMax = std::max(m_tMax, isect.time());
                m_tMin = std::min(m_tMin, isect.time());
            }
        }
    }

    sampler.stub();
}

art::Vector3 art::DepthMapIntegrator::Li(const Ray &ray, const Scene &scene,
                                         const Sampler &sampler) const
{
    Vector3 L((component_t)0, 0, 0); // The radiance
    // Find closest ray intersection or return background radiance.
    SurfaceInteraction isect;
    if (!scene.intersect(ray, &isect))
    {
        // If no object is found, get pixel from a far point
        component_t r = m_far_color[0] / 255.0;
        component_t g = m_far_color[1] / 255.0;
        component_t b = m_far_color[2] / 255.0;
        return Vector3{r, g, b};
    }
    else
    {

        // Get ray t parameter for which intersection occurred
        auto t = isect.time();

        // Linearly interpolate a color between white and black
        float a0 = (m_far_color[0] - m_near_color[0]) / (m_tMax - m_tMin);
        float a1 = (m_far_color[1] - m_near_color[1]) / (m_tMax - m_tMin);
        float a2 = (m_far_color[2] - m_near_color[2]) / (m_tMax - m_tMin);
        float r = m_near_color[0] + (a0) * (t - m_tMin) /255;
        float g = m_near_color[1] + (a1) * (t - m_tMin) /255;
        float b = m_near_color[2] + (a2) * (t - m_tMin) /255;

        return Vector3{r, g, b };
    }
    sampler.stub(); 
    return L;
}