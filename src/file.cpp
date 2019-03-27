#include "../include/file.h"
#include <typeinfo>

art::File::File(std::string filename)
	: m_filename(filename)
{ /*empty*/
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

	m_filename = j.at("scene").at("filename");

	return j;
}

/**
 * @brief Read json and save figures to canvas
 */
std::unique_ptr<art::Canvas> art::File::create_canvas(json &j)
{

	// Get scene
	auto scene = j.at("scene");
	std::cout << "scene\n";

	//Get canvas' data
	auto h = scene.at("camera").at("height");
	auto w = scene.at("camera").at("width");

	return std::make_unique<Canvas>(w, h);
}

void art::File::save_ppm(const art::Canvas &c)
{

	element_t *image = c.pixels();
	size_t width = c.width();
	size_t height = c.height();

	std::ofstream file;

	std::string folder = "gallery/";
	std::string extension = ".ppm";
	std::string path = folder + this->m_filename + extension;
	file.open(path);
	file << "P3"
		 << "\n";
	file << width << " "
		 << height << "\n";
	file << 255 << "\n";

	for (unsigned int x = 0; x < width; x++)
	{
		for (unsigned int y = 0; y < height; y++)
		{
			for (int z = 0; z < 3; z++)
			{
				auto index = height * width * z + width * y + x;
				file << static_cast<unsigned>(image[index]) << " ";
			}
		}
		file << "\n";
	}

	file.close();
}

/**
 * @brief Instantiate object
 */
std::unique_ptr<art::Background> art::File::create_background(json &j)
{
	auto scene = j.at("scene").at("background");
	std::string name = scene.at("type");
	std::cout << "type\n";

	if (name == "solid")
	{
		std::vector<color_t> color = scene.at("color");
		art::Color c = art::Color(color[0], color[1], color[2]);
		return std::make_unique<art::Background>(c, name);
	}
	else if (name == "gradient")
	{
		std::vector<std::vector<color_t>> color = scene.at("colors");
		art::Color c1 = art::Color(color[0][0], color[0][1], color[0][2]);
		art::Color c2 = art::Color(color[1][0], color[1][1], color[1][2]);
		art::Color c3 = art::Color(color[2][0], color[2][1], color[2][2]);
		art::Color c4 = art::Color(color[3][0], color[3][1], color[3][2]);
		return std::make_unique<art::Background>(c1, c2, c3, c4, name);
	}
	else
	{
		throw std::invalid_argument("Invalid syntax. Type not found: " + name);
	}

	//If fill=None, set the method
}