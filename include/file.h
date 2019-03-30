#ifndef _file_h_
#define _file_h_

#include <string>
#include <fstream>
#include <memory> //unique_ptr, make_unique

#include "color.h"
#include "buffer.h"
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
  std::unique_ptr<Buffer> create_canvas(json &j);

  std::unique_ptr<Background>  create_background(json &j);

  void save_ppm(const Buffer &b);

  /**
   * @brief Get filename to new image*
   */
  std::string new_name();


private:
  std::string m_filename;
  bool m_overwrite; //flag indicating if new image overwrite the old one

};
} // namespace rstzr

#endif