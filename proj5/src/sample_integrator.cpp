#include "../include/integrator/sample_integrator.h"


void art::SampleIntegrator::render(const Scene& scene) {
    // Always call the preprocess() before doing any rendering.
    // This might be just an empty method, or not, depending on the integrator's needs.
    preprocess(scene);
    std::cout << "render1\n";
    // This might just be a tile (part) of an image, rendered in parallel.
    auto h = camera->film()->height();
    std::cout << "render1.5\n";
    auto w = camera->film()->width();
    std::cout << "render2\n";
    for ( int y = 0 ; y < h ; y++ ) {
        for( int x = 0 ; x < w ; x++ ) {
            int _x = x/ w;
            int _y = y/ h;
            Ray ray = camera->generate_ray( _x , _y ); // Generate the ray from (x,y)
            Vector3 L = Li( ray, scene, *sampler.get() ); // Determine the color for the ray.
            camera->film()->pixel( x, y , L ); // Set color of pixel (x,y) to L.
        }
    }
    std::cout << "render3\n";  
}