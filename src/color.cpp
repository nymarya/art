#include "color.h"

art::Color::Color (color_t red, color_t green, color_t blue)
{
	m_channels = new color_t[3];
	m_channels[0] = red;
	m_channels[1] = green;
	m_channels[2] = blue;
}

art::Color::Color(float red, float green, float blue)
{
	m_channels = new color_t[3];
	m_channels[0] = 255 * red;
	m_channels[1] = 255 * green;
	m_channels[2] = 255 * blue;
}

art::Color& art::Color::Color::operator=( const Color& other ){
	if (this == &other) return *this;

	delete [] m_channels; //<! Deallocate old storage area.

	//<! Allocate new storage area
	m_channels = new color_t[3];

	//<! Copy content to new container
	for(auto i(0ul); i < 3; ++i)
		m_channels[i] = other.m_channels[i];

	return *this;
}

/**
 * @brief Override operator 'equal'
 */
bool art::Color::operator==(const Color &other) const{
	return ( other.red() == this->red() ) && ( other.green() == this->green() ) && ( other.blue() == this->blue() );
}

color_t art::Color::red() const{
    return m_channels[0];
}

color_t art::Color::green() const{
    return m_channels[1];
}

color_t art::Color::blue() const{
    return m_channels[2];
}