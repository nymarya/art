#include "../include/file/file.h"
#include <typeinfo>
#include <dirent.h>

art::File::File(std::string filename)
	: m_filename(filename),
	  m_extension("png"),
	  m_overwrite(false)
{
	/*empty*/
}
/**
 * @brief Read json and save figures to canvas
 */
json art::File::read()
{
	// read a JSON file
	std::ifstream input(m_filename);
	json j;
	input >> j;

	try
	{
		m_filename = j.at("filename");
	}
	catch (json::exception e)
	{

		//if no filename if informed, use
		// the name of the file describing the scene
		m_filename = m_filename.substr(0, m_filename.find(".json"));
	}

	try
	{
		m_overwrite = j.at("overwrite_file");
	}
	catch (json::exception e)
	{
		//does nothing
	}

	return j;
}

/**
 * @brief Read json and save figures to canvas
 */
std::shared_ptr<art::Buffer> art::File::create_canvas(json &j)
{

	//Get canvas' data
	auto h = j.at("camera").at("height");
	auto w = j.at("camera").at("width");

	return std::make_shared<Buffer>(w, h);
}

/**
 * @brief Save image to file
 */
void art::File::save(size_t width, size_t height, const element_t *data)
{
	file_methot_t save_method = funcMap[m_extension];
	(this->*save_method)(width, height, data);
}

void art::File::save_ppm(size_t width, size_t height, const element_t *data)
{
	std::ofstream file;

	std::string folder = "gallery/";
	std::string extension = ".ppm";
	std::string path = folder + this->new_name() + extension;
	file.open(path);
	file << "P3"
		 << "\n";
	file << width << " "
		 << height << "\n";
	file << 255 << "\n";

	for (int y = height - 1; y >= 0; y--)
	{
		for (size_t x = 0; x < width; x++)
		{
			for (size_t z = 0u; z < 3u; z++)
			{
				//y * width + x + width * height * 2
				auto index = y * width + x + width * height * z;
				file << static_cast<unsigned>(data[index]) << " ";
			}
		}
		file << "\n";
	}

	file.close();
}

/**
 * @brief Save image to .png file.
 */
void art::File::save_png(const size_t width, const size_t height, const element_t *data)
{
	std::string folder = "gallery/";
	std::string extension = ".png";
	std::string path = folder + this->new_name() + extension;

    std::ofstream file;
	file.open (path);
  	file << "P3\n";
	file << width << " "
		 << height << "\n";
	file << 255 << "\n";

	for (int y = height - 1; y >= 0; y--)
	{
		for (size_t x = 0; x < width; x++)
		{
			for (size_t z = 0u; z < 3u; z++)
			{
				//y * width + x + width * height * 2
				auto index = y * width + x + width * height * z;
				file << static_cast<unsigned>(data[index]) << " ";
			}
		}
		file << "\n";
	}

	file.close();
}

/**
 * @brief Instantiate object
 */
std::shared_ptr<art::Background> art::File::create_background(json &j)
{
	auto scene = j.at("scene").at("background");
	std::string name = scene.at("type");

	if (name == "solid")
	{
		std::vector<color_t> color = scene.at("color");
		art::Color c = art::Color(color[0], color[1], color[2]);
		return std::make_unique<art::Background>(c, name);
	}
	else if (name == "gradient")
	{
		std::vector<std::vector<color_t>> color = scene.at("colors");
		std::vector<Color> bkg_colors;
		for (auto i = 0u; i < color.size(); i++)
			bkg_colors.push_back(art::Color(color[i][0], color[i][1], color[i][2]));

		return std::make_unique<art::Background>(bkg_colors[0],
												 bkg_colors[1],
												 bkg_colors[2],
												 bkg_colors[3], name);
	}
	else
	{
		throw std::invalid_argument("Invalid syntax. Type not found: " + name);
	}
}

std::unique_ptr<art::Camera> art::File::create_camera(json &j)
{
	auto camera = j.at("camera");
	std::string name = camera.at("type");

	size_t w = camera.at("width");
	size_t h = camera.at("height");
	auto pos = camera.at("position");
	Vector3 position(pos[0], pos[1], pos[2]);
	auto t = camera.at("target");
	Vector3 target(t[0], t[1], t[2]);
	auto u = camera.at("up");
	Vector3 up(u[0], u[1], u[2]);

	if (name == "orthographic")
	{
		auto vdim = camera.at("vpdim");

		int *vpdim = new int[4];
		vpdim[0] = vdim.at("b");
		vpdim[1] = vdim.at("l");
		vpdim[2] = vdim.at("r");
		vpdim[3] = vdim.at("t");
		return std::make_unique<art::OrthoCamera>(w, h, position, target,
												  up, vpdim);
	}
	else if (name == "perspective")
	{
		float fovy = camera.at("fovy");
		float aspect = camera.at("aspect");
		float fdis = camera.at("fdistance");

		return std::make_unique<art::PerspectiveCamera>(w, h, position, target,
														up, fovy, aspect, fdis);
	}
	else
	{
		throw std::invalid_argument("Invalid syntax. Type not found: " + name);
	}
}

/**
 * @brief Create primitive object based on the objects of
 * the scene, which are defined at the json file.
 */
std::shared_ptr<art::Primitive> art::File::create_primitives(json &j)
{

	auto objects = j.at("scene").at("objects");

	std::vector<std::shared_ptr<Primitive>> primitives;

	// Create shapes
	for (auto object : objects)
	{
		std::string type = object.at("type");
		std::string name = object.at("name");
		std::string material_key = object.at("material");

		std::shared_ptr<Material> material = m_materials[material_key];

		if (type == "sphere")
		{
			auto radius = object.at("radius");
			auto v_center = object.at("center");
			Vector3 center = Vector3(v_center.at("x"), v_center.at("y"),
									 v_center.at("z"));
			//Create shape and primitive
			std::shared_ptr<Sphere> shape = std::make_shared<art::Sphere>(center,
																		  radius, name, material.get());
			primitives.push_back(std::make_shared<art::GeometricPrimitive>(shape, material));
		}
		else
		{
			throw std::invalid_argument("Invalid syntax. Type not found: " + type);
		}
	}

	auto agg = std::make_shared<AggregatePrimitive>(primitives);
	return agg;
}

/**
 * @brief Create a integrator object
 */
std::unique_ptr<art::Integrator> art::File::create_integrator(json &j, std::shared_ptr<Camera> camera,
															  std::shared_ptr<art::Sampler> sampler)
{
	auto integrator = j.at("running").at("integrator");
	std::string type = integrator.at("type");
	if (type == "flat")
	{
		return std::make_unique<FlatIntegrator>(camera, sampler);
	}
	else if (type == "depth_map")
	{
		auto fc = integrator.at("far_color");
		Vector3 far_color = Vector3( fc.at("r"), fc.at("g"), fc.at("b") );

		auto nc = integrator.at("near_color");
		Vector3 near_color = Vector3( nc.at("r"), nc.at("g"), nc.at("b") );

		return std::make_unique<DepthMapIntegrator>(camera, sampler, far_color, near_color);
	}
	else if (type == "normal")
	{
		return std::make_unique<NormalMapIntegrator>(camera, sampler);
	}
	else if (type == "whitted")
	{
		return std::make_unique<BlinnPhongIntegrator>(camera, sampler);
	}
	else
	{
		throw std::invalid_argument("Invalid syntax. Type not found: " + type);
	}
}

/**
* @brief Get filenama to new image*
*/
std::string art::File::new_name()
{
	if (!m_overwrite)
	{
		//Rename file if necessary
		// @see https://stackoverflow.com/questions/612097/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c
		DIR *dir;
		struct dirent *ent;
		if ((dir = opendir("./gallery")) != NULL)
		{
			int file = 0;
			while ((ent = readdir(dir)) != NULL)
			{
				// count how many files with that name exists
				std::string name = ent->d_name;
				bool exists_one = name.substr(0, name.find(".")) == m_filename;
				bool exists_more = name.substr(0, name.find_last_of("_")) == m_filename;
				if (exists_one || exists_more)
					file++;
			}
			return m_filename + "_" + std::to_string(file);
			closedir(dir);
		}
		else
		{
			/* could not open directory */
		}
	}
	return m_filename;
}

/**
 * @brief Get the material object
 * 
 * @param name 
 * @return std::shared_ptr<Material> 
 */
std::shared_ptr<art::Material> art::File::material(std::string name)
{
	return m_materials[name];
}

/**
 * @brief Load material from json into map.
 * 
 * @param j 
 */
void art::File::load_materials(json &j)
{
	auto materials = j.at("scene").at("materials");
	for (auto material : materials)
	{
		std::string type = material.at("type");
		std::string name = material.at("name");

		if (type == "flat")
		{
			auto diffuse = material.at("diffuse");
			auto r = diffuse.at("r");
			auto g = diffuse.at("g");
			auto b = diffuse.at("b");
			m_materials[name] = std::make_shared<FlatMaterial>(r, g, b, name);
		} else if (type == "blinn"){
			auto ambient = material.at("ambient");
			component_t r = ambient.at("r");
			component_t g = ambient.at("g");
			component_t b = ambient.at("b");
			Vector3 v_ambient(r,g ,b);

			auto diffuse = material.at("diffuse");
			r = diffuse.at("r");
			g = diffuse.at("g");
			b = diffuse.at("b");
			Vector3 v_diffuse(r, g, b);

			auto specular = material.at("specular");
			r = specular.at("r");
			g = specular.at("g");
			b = specular.at("b");
			Vector3 v_specular(r, g, b);

			float gloss = material.at("glossiness");
			m_materials[name] = std::make_shared<BlinnMaterial>(v_ambient, v_diffuse, 
																v_specular, gloss, name);
		}
		else
		{
			throw std::invalid_argument("Invalid syntax. Type not found: " + type);
		}
	}
}

/**
 * @brief Load lights defined at the scene file.
 */
std::vector<std::shared_ptr<art::Light>> art::File::load_lights(json &j)
{
	auto lights = j.at("scene").at("lights");
	std::vector<std::shared_ptr<art::Light>> result;
	for (auto light : lights)
	{
		std::string type = light.at("type");
		std::string name = light.at("name");

		if (type == "ambient")
		{
			auto intensity = light.at("intensity");
			component_t r = intensity.at("r");
			component_t g = intensity.at("g");
			component_t b = intensity.at("b");

			Vector3 rgb{r, g, b};
			m_lights[name] = std::make_shared<AmbientLight>(rgb, name);
			result.push_back(m_lights[name]);
		}
		else if (type == "point")
		{
			auto intensity = light.at("intensity");
			component_t r = intensity.at("r");
			component_t g = intensity.at("g");
			component_t b = intensity.at("b");
			Vector3 rgb{r, g, b};

			auto position = light.at("position");
			component_t x = position.at("x");
			component_t y = position.at("y");
			component_t z = position.at("z");
			Vector3 xyz{x, y, z};

			m_lights[name] = std::make_shared<PointLight>(rgb, name, xyz);
			result.push_back(m_lights[name]);
		}
		else
		{
			throw std::invalid_argument("Invalid syntax. Type not found: " + type);
		}
	}

	return result;
}