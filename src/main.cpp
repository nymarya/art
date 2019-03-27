#include <iostream>
#include <memory>

#include "vector3.h"
#include "file.h"
#include "json.hpp"
#include "canvas.h"
#include "background.h"

using namespace art;

int main()
{

     // Read file
     File file("scene.json");
     json j = file.read();

     std::unique_ptr<Canvas> c = file.create_canvas(j);
     std::unique_ptr<Background> background = file.create_background(j);

     auto w = c->height();
     auto h = c->width();
     for (int j = h - 1; j >= 0; j--)
     {
          for (int i = 0; i < w; i++)
          {
               // Not shooting rays just yet; so let us sample the background.
               auto color = background->color(float(i) / float(w), float(j) / float(h)); // get background color.
               c->pixel(i, j, color);                                          // set image buffer at position (i,j), accordingly.
          }
     }

     file.save_ppm(*c.get());
}