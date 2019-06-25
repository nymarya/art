#ifndef _file_h_
#define _file_h_

#include <string>
#include <fstream>
#include <memory> //unique_ptr, make_unique, shared_ptr
#include <map> //map

#include "../color.h"
#include "../buffer.h"
#include "../background.h"
#include "../camera/camera.h"
#include "../camera/ortho_camera.h"
#include "../camera/perspective_camera.h"
#include "../integrator/integrator.h"
#include "../integrator/flat_integrator.h"
#include "../integrator/depth_map_integrator.h"
#include "../integrator/normal_map_integrator.h"
#include "../light/ambient_light.h"
#include "../light/point_light.h"
#include "../material/flat_material.h"
#include "../primitive/aggregate_primitive.h"
#include "../primitive/geometric_primitive.h"
#include "../shape/shape.h"
#include "../shape/sphere.h"

#include "../common.h"

#include "json.hpp"

using json = nlohmann::json;

namespace art
{
constexpr int stride = 0;
constexpr int depth = 3;
/**
 * Provide the method to read and save files
 */
class File
{
typedef void (File::*file_methot_t)(size_t width, size_t height, const element_t * data);

public:
  File():m_extension("png"){}
  File(std::string filename);

  ~File() = default;

  /**
   * @brief Read json and return it
   */
  json read();

  /**
   * @brief Create a canvas object based on the json read.
   */
  std::shared_ptr<Buffer> create_canvas(json &j);

  std::shared_ptr<Background>  create_background(json &j);

  /**
   * @brief Create camera object based on the json read.
   */
  std::unique_ptr<Camera>  create_camera(json &j);

  /**
   * @brief Create primitive object based on the objects of
   * the scene, which are defined at the json file.
   */
  std::shared_ptr<Primitive> create_primitives(json &j);

  /**
   * @brief Create a integrator object
   * 
   * @param j 
   * @param camera 
   * @param sampler 
   * @return std::unique_ptr<Integrator> 
   */
  std::unique_ptr<Integrator> create_integrator(json &j, std::shared_ptr<Camera> camera, std::shared_ptr<Sampler> sampler);

  /**
   * @brief Load lights defined at the scene file.
   * 
   * @param j 
   * @return std::vector<std::shared_ptr<Light>> 
   */
  std::vector<std::shared_ptr<Light>> load_lights(json &j);

  /**
   * @brief Save image to file
   */
  void save(size_t width, size_t height, const element_t * data);

  /**
   * @brief Save image to .ppm file.
   */
  void save_ppm(size_t width, size_t height, const element_t * data);

  /**
   * @brief Save image to .png file.
   */
  void save_png(size_t width, size_t height, const element_t * data);

  /**
   * @brief Get filename to new image*
   */
  std::string new_name();

  /**
   * @brief Get the material object
   * 
   * @param name 
   * @return std::shared_ptr<Material> 
   */
  std::shared_ptr<Material> material(std::string name);

  /**
   * @brief Load material from json into map.
   * 
   * @param j 
   */
  void load_materials(json &j);

  /**
   * @brief Set filename to be read
   * 
   * @param name 
   */
  void name(std::string name)
  {m_filename = name;}

private:
  std::string m_filename, m_extension;
  bool m_overwrite; //flag indicating if new image overwrite the old one

  //Map the functions to save a file
  std::map<std::string, file_methot_t> funcMap = {
    std::pair<std::string, file_methot_t>("ppm", &File::save_ppm),
    std::pair<std::string, file_methot_t>("png", &File::save_png) 
  };

  //Map of materials
  std::map<std::string, std::shared_ptr<Material>> m_materials;

  //Map of lights
  std::map<std::string, std::shared_ptr<Light>> m_lights;

};
} // namespace rstzr

#endif