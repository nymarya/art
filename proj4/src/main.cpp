#include <iostream>
#include <memory>

#include "vector3.h"
#include "camera.h"
#include "color.h"
#include "file.h"
#include "json.hpp"
#include "buffer.h"
#include "background.h"
#include "primitive.h"

using namespace art;

int main()
{
     // Read file
     File file("scene.json");
     json j = file.read();

     std::vector<std::shared_ptr<Primitive>> scene;
     std::shared_ptr<Camera> cam = file.create_camera(j);
     std::unique_ptr<Buffer> c = file.create_canvas(j);
     std::unique_ptr<Background> background = file.create_background(j);

     auto h = c->height();
     auto w = c->width();
     for (auto i = 0; i < h; i++)
     {
          for (auto j = 0u; j < w; j++)
          {
               Point3 screen_coord(float(i) / float(w), float(j) / float(h), 0);
               // Generate ray with the Shirley method.
               Ray ray = cam->generate_ray(j, i);
               auto color = background->color(float(j) / float(w), float(i) / float(h)); // get background color.
               for (const Primitive &p : scene)
               {                                                  // Traverse each object.
                    if (p.intersect_p(ray))                       // Does the ray hit any sphere in the scene?
                         color = Vector3(255, 255, 255);              // Just paint it red.
                    c->pixel((h-1) * i, j, color); // set image buffer at position (i,j), accordingly.
               }
          }
     }

     file.save(w, h, c->pixels());
}