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

     std::vector<std::shared_ptr<Primitive>> scene;

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
               for (const std::shared_ptr<art::Primitive> &p : scene)
               {                                         // Traverse each object.
                    if (p->intersect_p(ray))             // Does the ray hit any sphere in the scene?
                         color = Vector3(255, 255, 255); // Just paint it red.
                    c->pixel((h - 1) * i, j, color);     // set image buffer at position (i,j), accordingly.
               }
          }
     }

     file.save(w, h, c->pixels());
}

void init_engine()
{
     // [1] Parser and load scene file
     // Read file
     File file("scene.json");
     json j = file.read();
     // Load background info.
     std::unique_ptr<Background> background = file.create_background(j);
     // Load Film info.
     std::unique_ptr<Buffer> c = file.create_canvas(j);
     // Load Camera info and creates the global camera object.
     std::shared_ptr<Camera> g_camera = file.create_camera(j);

     // create a aggregate primitive
     //AggregatePrimitive *aggregate = new AggregatePrimitive(parser.primitives);
     std::shared_ptr<Primitive> agg = file.create_primitives(j);

     std::shared_ptr<Sampler> sampler(new Sampler());
     if (parser.integrator.compare("flat") == 0)
     {
          FlatIntegrator *fi = new FlatIntegrator(parser.camera, sampler);
          g_integrator = std::unique_ptr<Integrator>(fi);
     }

     g_integrator = std::make_unique<FlatIntegrator>(cam, sampler);
     // We create the scene last, because we need all the other objects first.
     // create a scene
     Scene scene = Scene(agg, background, lights);
     g_scene = std::make_unique<Scene>(scene);
}