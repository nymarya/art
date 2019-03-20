#include "../include/file.h"
#include <typeinfo>

art::File::File(std::string filename)
	: m_filename(filename)
{ /*empty*/
}
/**
 * @brief Read json and save figures to canvas
 */
std::unique_ptr<art::Background> art::File::read()
{
	// read a JSON file
	std::ifstream input(m_filename);
	json j;
	input >> j;

	// Get scene
	auto scene = j.at("scene");
	std::cout << "scene\n";

	//Get canvas' data
	auto h = scene.at("camera").at("height");
	auto w = scene.at("camera").at("width");
	std::cout << "cam\n";

	m_filename = scene.at("filename");

	return create_background(scene.at("background"), w, h);
}

void art::File::save_ppm(const art::Background &b)
{

	component *image = b.pixels();
	size_t width = b.width();
	size_t height = b.height();

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
std::unique_ptr<art::Background> art::File::create_background(json &j, size_t w, size_t h)
{

	std::string name = j.at("type");
	std::cout << "type\n";

	if (name == "solid")
	{
		std::vector<color_t> color = j.at("color");
		art::Color c = art::Color(color[0], color[1], color[2]);
		return std::make_unique<art::Background>(c, w, h);
	}
	else if (name == "gradient")
	{
		std::vector<color_t> color = j.at("colors");
		art::Color c1 = art::Color(color[0], color[1], color[2]);
		art::Color c2 = art::Color(color[0], color[1], color[2]);
		art::Color c3 = art::Color(color[0], color[1], color[2]);
		art::Color c4 = art::Color(color[0], color[1], color[2]);
		return std::make_unique<art::Background>(c1, c2, c3, c4, w, h);
	}
	else
	{
		throw std::invalid_argument("Invalid syntax. Type not found: " + name);
	}

	//If fill=None, set the method
}