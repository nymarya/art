#include <iostream>
#include <memory>

#include "vector3.h"
#include "camera.h"
#include "file.h"
#include "json.hpp"
#include "buffer.h"
#include "background.h"

using namespace art;

int main()
{
     // Read file
     File file("scene.json");
     json j = file.read();

     std::unique_ptr<Camera> cam = file.create_camera(j);
     std::unique_ptr<Buffer> c = file.create_canvas(j);
     std::unique_ptr<Background> background = file.create_background(j);

     auto h = c->height();
     auto w = c->width();
     for (int j = h - 1; j >= 0; j--)
     {
          for (auto i = 0u; i < w; i++)
          {
               Point3 screen_coord( float(i)/float(w), float(j)/float(h), 0 );
               Ray r = cam->generate_ray( screen_coord.x(), screen_coord.y() ); // Get ray from the camera object.
               //bool hit = Trace( r, scene ); // Test whether the ray hit anything. (TODO)
               bool hit = false;
               auto color = ( hit ) ?  Vector3(255,0,0) :  // Just paint it red.
                         background->color(float(i) / float(w), float(j) / float(h)); // get background color.
               c->pixel(i, j, color);                                          // set image buffer at position (i,j), accordingly.
          }
     }

     file.save(w, h, c->pixels());
}