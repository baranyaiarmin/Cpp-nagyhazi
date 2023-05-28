#include "Center.h"
#include <sstream>

std::string Center::toString()
{
	std::stringstream stream;
	stream << "Name: " << getName() << std::endl << "Team: " << getTeam() << std::endl << "Position: " << position << std::endl << "Height: " << getHeight() << std::endl << "Age: " << getAge() << std::endl << "Rating: " << getRating() << std::endl;

	std::string text = stream.str();
	return text;
}