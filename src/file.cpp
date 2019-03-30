#include "../include/file.h"
#include <typeinfo>
#include <dirent.h>

art::File::File(std::string filename)
	: m_filename(filename), m_overwrite(false),
	m_extension(".ppm")
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
		m_filename = j.at("scene").at("filename");
	}
	catch (json::exception e)
	{

		//if no filename if informed, use
		// the name of the file describing the scene
		m_filename = m_filename.substr(0, m_filename.find(".json"));
	}

	try
	{
		m_overwrite = j.at("scene").at("overwrite_file");
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
std::unique_ptr<art::Buffer> art::File::create_canvas(json &j)
{

	// Get scene
	auto scene = j.at("scene");

	//Get canvas' data
	auto h = scene.at("camera").at("height");
	auto w = scene.at("camera").at("width");

	return std::make_unique<Buffer>(w, h);
}

/**
 * @brief Save image to file
 */
void art::File::save(const Buffer &b){
	file_methot_t save_method = funcMap[m_extension];
	(this->*save_method)(b);
}


void art::File::save_ppm(const art::Buffer &c)
{

	element_t *image = c.pixels();
	size_t width = c.width();
	size_t height = c.height();

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

	for (size_t y = height - 1; y > 0; --y)
	{
		for (size_t x = 0; x < width; x++)
		{
			for (size_t z = 0u; z < 3u; z++)
			{
				//y * width + x + width * height * 2
				auto index = y * width + x + width * height * z;
				file << static_cast<unsigned>(image[index]) << " ";
			}
		}
		file << "\n";
	}

	file.close();
}

/**
 * @brief Save image to .png file.
 */
void art::File::save_png(const art::Buffer &b){
	std::string folder = "gallery/";
	std::string extension = ".png";
	std::string path = folder + this->new_name() + extension;

	int w = b.width();
	int h = b.height();

	//stbi_write_png(path, w, h, int comp, const void *data, int stride_in_bytes);

}

/**
 * @brief Instantiate object
 */
std::unique_ptr<art::Background> art::File::create_background(json &j)
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
}

/**
* @brief Get filenama to new image*
*/
std::string art::File::new_name()
{
	if (m_overwrite)
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