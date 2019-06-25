#include <iostream>
#include <memory>

#include "background.h"
#include "buffer.h"
#include "camera/camera.h"
#include "color.h"
#include "file/file.h"
#include "file/json.hpp"
#include "geometry/vector3.h"
#include "primitive/primitive.h"
#include "sampler.h"

using namespace art;

std::shared_ptr<Integrator> g_integrator;
std::unique_ptr<Scene> g_scene;
std::shared_ptr<Camera> g_camera;
std::unique_ptr<File> file;

void init_engine(std::string filename)
{
     // [1] Parser and load scene file
     // Read file
     file = std::make_unique<File>();
     file->name(filename);
     json j = file->read();

     // Load background info.
     std::shared_ptr<Background> background = file->create_background(j);
     
     // Load Film info.
     std::shared_ptr<Buffer> c = file->create_canvas(j);
     
     // Load Camera info and creates the global camera object.
     g_camera = file->create_camera(j);
     g_camera->film(c);

     // Load all materials and create a aggregate primitive
     file->load_materials(j);
     std::shared_ptr<Primitive> agg = file->create_primitives(j);

     std::shared_ptr<Sampler> sampler(new Sampler());

     g_integrator = file->create_integrator(j, g_camera, sampler);

     // Retrieve the lights
     std::vector<std::shared_ptr<Light>> lights = file->load_lights(j);
     // We create the scene last, because we need all the other objects first.
     // create a scene
     Scene scene = Scene(agg, background, lights);
     g_scene = std::make_unique<Scene>(scene);
}

void run()
{
     g_integrator->render(*g_scene); // Activate the main loop
}

int main(int argc, char *argv[])
{

     std::string filename;
     if (argc == 2)
          filename = argv[1];
     else
     {
          std::cerr << "File not found\n";
          return 0;
     }

     init_engine(filename);

     run();

     auto w = g_camera->film()->width();
     auto h = g_camera->film()->height();
     // Send image color buffer to the output file.
     file->save(w, h, g_camera->film()->pixels());

     return EXIT_SUCCESS;
}