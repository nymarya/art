#ifndef _file_h_
#define _file_h_

#include <string>
#include <fstream>
#include <memory> //unique_ptr, make_unique

#include "color.h"
#include "canvas.h"
#include "background.h"

#include "common.h"

#include "json.hpp"

using json = nlohmann::json;
namespace art
{
/**
 * Provide the method to read and save files
 */
class File
{

public:
  File(std::string filename);

  ~File() = default;

  /**
   * @brief Read json and return it
   */
  json read();

  /**
   * @brief Create a canvas object based on the json read.
   */
  std::unique_ptr<Canvas> create_canvas(json &j);

  std::unique_ptr<Background>  create_background(json &j);

  void save_ppm(const Canvas &b);

private:
  std::string m_filename;

};
} // namespace rstzr

#endif