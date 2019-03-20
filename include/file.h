#ifndef _file_h_
#define _file_h_

#include <string>
#include <fstream>
#include <memory> //unique_ptr, make_unique

#include "background.h"
#include "color.h"

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
   * @brief Read json and save figures to canvas
   */
  std::unique_ptr<Background> read();

  void save_ppm(const Background &b);

private:
  std::string m_filename;

  std::unique_ptr<Background>  create_background(json &j, size_t w, size_t h);

};
} // namespace rstzr

#endif