#include "../include/file.h"
#include <typeinfo>
#include <dirent.h>

art::File::File(std::string filename)
	: m_filename(filename),
	m_extension("ppm"),
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
void art::File::save(size_t width, size_t height, const element_t * data){
	file_methot_t save_method = funcMap[m_extension];
	(this->*save_method)(width, height, data);
}


void art::File::save_ppm(size_t width, size_t height, const element_t * data)
{

	//element_t *image = c.pixels();
	//size_t width = c.width();
	//size_t height = c.height();

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
void art::File::save_png( const size_t width, const size_t height, const element_t * data){
	std::string folder = "gallery/";
	std::string extension = ".png";
	std::string path = folder + this->new_name() + extension;

	//stbi_write_png(path.c_str, width, height, depth, data, stride);

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
		std::vector<Color> bkg_colors;
		for(auto i=0u; i< color.size(); i++)
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
	auto camera = j.at("scene").at("camera");
	std::string name = camera.at("type");

	if (name == "orthographic")
	{
		auto w = camera.at("width");
		auto h = camera.at("height");

		return std::make_unique<art::OrthoCamera>(w, h);
	}
	else if (name == "perspective")
	{
		auto w = camera.at("width");
		auto h = camera.at("height");

		return std::make_unique<art::PerspectiveCamera>(w, h);
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