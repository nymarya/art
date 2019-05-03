#include "sample_integrator.h"


void art::SampleIntegrator::render(const Scene& scene) {
    // Always call the preprocess() before doing any rendering.
    // This might be just an empty method, or not, depending on the integrator's needs.
    preprocess(scene);

    // This might just be a tile (part) of an image, rendered in parallel.
    Point img_dim = camera->film->dimensions();
    for ( int y = 0 ; y < img_dim.y ; y++ ) {
        for( int x = 0 ; x < img_dim.x ; x++ ) {
            //Point3 screen_coord{ float(x)/float(img_dim.x), float(y)/float(img_dim.y) };
            Ray ray = camera->generate_ray( float(x)/float(img_dim.x), float(y)/float(img_dim.y) ); // Generate the ray from (x,y)
            Color L = Li( ray, scene, sampler ); // Determine the color for the ray.
            camera->film->add_sample( Point2i( x, y ), L ); // Set color of pixel (x,y) to L.
        }
    }
    // Send image color buffer to the output file.
    camera->film->write_img( image );
}