#include "integrator/sample_integrator.h"


void art::SampleIntegrator::render(const Scene& scene) {
    // Always call the preprocess() before doing any rendering.
    // This might be just an empty method, or not, depending on the integrator's needs.
    preprocess(scene);

    // This might just be a tile (part) of an image, rendered in parallel.
    auto h = camera->height;
    auto w = camera->width;
    for ( int y = 0 ; y < h ; y++ ) {
        for( int x = 0 ; x < w ; x++ ) {
            Point2D screen_coord{ float(x)/float(w), float(y)/float(h) };
            Ray ray = camera->generate_ray( (component_t) float(x)/float(w), 
                                            (component_t) float(y)/float(h) ); // Generate the ray from (x,y)
            Color L = Li( ray, scene, sampler.get() ); // Determine the color for the ray.
            camera->film->add_sample( Point2D( x, y ), L ); // Set color of pixel (x,y) to L.
        }
    }
    // Send image color buffer to the output file.
    file.save(w, h, camera->film->pixels());   
}