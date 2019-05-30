#include "../include/integrator/sample_integrator.h"


void art::SampleIntegrator::render(const Scene& scene) {
    // Always call the preprocess() before doing any rendering.
    // This might be just an empty method, or not, depending on the integrator's needs.
    preprocess(scene);
    
    // This might just be a tile (part) of an image, rendered in parallel.
    auto h = m_camera->film()->height();
    auto w = m_camera->film()->width();
    for ( int y = 0 ; y < h ; y++ ) {
        for( int x = 0 ; x < w ; x++ ) {
            std::cout << "x " << x << " y " << y << "\n";
            float _x = x/ (float)w;
            float _y = y/ (float)h;
            Ray ray = m_camera->generate_ray( _x , _y ); // Generate the ray from (x,y)
            std::cout << ray << std::endl;
            Vector3 L = Li( ray, scene, *m_sampler.get() ); // Determine the color for the ray.
            m_camera->film()->pixel( x, y , L ); // Set color of pixel (x,y) to L.
        }
    }
}