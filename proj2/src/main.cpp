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
               // Generate ray with the view plane frame method.
               Ray r1 = cam->generate_ray( float(i)/float(w), float(j)/float(h) );
               // Generate ray with the Shirley method.
               Ray r2 = cam->generate_ray( i, j );
               // Print out the two rays, that must be the same (regardless of the method).
               //std::cout << r1 << std::endl;
               //std::cout << r2 << std::endl;
               auto color = background->color(float(i) / float(w), float(j) / float(h)); // get background color.
               c->pixel(i, j, color);                                          // set image buffer at position (i,j), accordingly.
          }
     }

     file.save(w, h, c->pixels());
}