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
     std::cout << "init1\n";
     // [1] Parser and load scene file
     // Read file
     file = std::make_unique<File>();
     file->name(filename);
     std::cout << "init0\n";
     json j = file->read();
     std::cout << "init1\n";
     // Load background info.
     std::shared_ptr<Background> background = file->create_background(j);
     std::cout << "init2\n";
     // Load Film info.
     std::unique_ptr<Buffer> c = file->create_canvas(j);
     std::cout << "init3\n";
     // Load Camera info and creates the global camera object.
     std::shared_ptr<Camera> g_camera = file->create_camera(j);
     std::cout << "init4\n";

     // Load all materials and create a aggregate primitive
     file->load_materials(j);
     std::cout << "init4.5\n";
     std::shared_ptr<Primitive> agg = file->create_primitives(j);
     std::cout << "init5\n";

     std::shared_ptr<Sampler> sampler(new Sampler());
     std::cout << "init6\n";

     g_integrator = file->create_integrator(j, g_camera, sampler);
     std::cout << "init7\n";
     // We create the scene last, because we need all the other objects first.
     // create a scene

     Scene scene = Scene(agg, background);
     g_scene = std::make_unique<Scene>(scene);
     std::cout << "init8\n";
}

void run()
{
     std::cout << "run0\n";
     *g_scene;
     std::cout << "run1\n";
     g_integrator->render(*g_scene); // Activate the main loop
     std::cout << "run2\n";
}

int main(int argc, char *argv[])
{

     std::string filename;
     if (argc == 2)
          filename = argv[1];
     else
     {
          std::cout << "File not found\n";
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