#include <iostream>
#include <memory>

#include "vector3.h"
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

     std::unique_ptr<Buffer> c = file.create_canvas(j);
     std::unique_ptr<Background> background = file.create_background(j);

     auto h = c->height();
     auto w = c->width();
     for (int j = h - 1; j >= 0; j--)
     {
          for (auto i = 0u; i < w; i++)
          {
               // Not shooting rays just yet; so let us sample the background.
               auto color = background->color(float(i) / float(w), float(j) / float(h)); // get background color.
               c->pixel(i, j, color);                                          // set image buffer at position (i,j), accordingly.
          }
     }

     file.save(w, h, c->pixels());
}