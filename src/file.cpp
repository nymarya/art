#include "../include/file.h"
#include <typeinfo>

art::File::File(std::string filename)
	: m_filename(filename)
{ /*empty*/
}
/**
 * @brief Read json and save figures to canvas
 */
void art::File::read()
{
	// read a JSON file
	std::ifstream input(m_filename);
	json j;
	input >> j;

	// Get scene
	auto scene = j.at("scene");

	//Get canvas' data
	auto h = scene.at("camera").at("height");
	auto w = scene.at("camera").at("width");
	Canvas copy(w, h);
	c = copy;

	m_filename = scene.at("filename");



}

void  art::File::save_ppm(const rstzr::Canvas &canvas)
{

	component_t *image = canvas.pixels();
	size_t width = canvas.width();
	size_t height = canvas.height();

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
void create_background(json &j)
{

	std::string name = j.at("type");

	if (name == "solid")
	{
		std::string color = j.at('color');
		return art::Background( art::Color(color));
	}
	else if (name == "gradient")
	{
		std::string color = j.at('colors');
		return art::Background( Color(color[0]), Color(color[1]), Color(color[2]), Color(color[3]));
	}
	else
	{
		throw std::invalid_argument("Invalid syntax. Type not found: " + name);
	}

	//If fill=None, set the method
}