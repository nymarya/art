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
  void read();

  void save_ppm(const Background &b);

private:
  std::string m_filename;

};
} // namespace rstzr

#endif