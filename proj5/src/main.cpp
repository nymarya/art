#include <iostream>
#include <memory>

#include "vector3.h"
#include "camera.h"
#include "color.h"
#include "file/file.h"
#include "json.hpp"
#include "buffer.h"
#include "background.h"
#include "primitive.h"
#include "sampler.h"

using namespace art;

std::shared_ptr<Integrator> g_integrator;
std::unique_ptr<Scene> g_scene;

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

     g_integrator = file.create_integrator(j, g_camera, sampler);
     // We create the scene last, because we need all the other objects first.
     // create a scene
     
     Scene scene = Scene(agg, std::make_shared<Background>(background.get()));
     g_scene = std::make_unique<Scene>(scene);
}

void run()
{
    g_integrator->render( *g_scene ); // Activate the main loop
}

int main()
{
     init_engine();

     run();

     return EXIT_SUCCESS;
}