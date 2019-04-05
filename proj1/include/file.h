#ifndef _file_h_
#define _file_h_

#include <string>
#include <fstream>
#include <memory> //unique_ptr, make_unique
#include <map> //map

#include "color.h"
#include "buffer.h"
#include "background.h"

#include "common.h"

#include "json.hpp"
#include "stb_image_write.h"

using json = nlohmann::json;

namespace art
{

/**
 * Provide the method to read and save files
 */
class File
{
typedef void (File::*file_methot_t)(const Buffer&);
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
  std::unique_ptr<Buffer> create_canvas(json &j);

  std::unique_ptr<Background>  create_background(json &j);

  /**
   * @brief Save image to file
   */
  void save(const Buffer &b);

  /**
   * @brief Save image to .ppm file.
   */
  void save_ppm(const Buffer &b);

  /**
   * @brief Save image to .png file.
   */
  void save_png(const Buffer &b);

  /**
   * @brief Get filename to new image*
   */
  std::string new_name();


private:
  std::string m_filename, m_extension;
  bool m_overwrite; //flag indicating if new image overwrite the old one

  //Map the functions to save a file
  std::map<std::string, file_methot_t> funcMap = {
    std::pair<std::string, file_methot_t>("ppm", &File::save_ppm),
    std::pair<std::string, file_methot_t>("png", &File::save_png) 
  };

};
} // namespace rstzr

#endif