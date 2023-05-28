#include <iostream>
#include <string>
#include <sstream>
#include "Players.h"

std::string Player::toString()
{
	std::stringstream stream;
	stream << "Name: " << name << std::endl << "Team: " << team << std::endl << "Height: " << height << std::endl << "Age: " << age << std::endl <<"Rating: " << getRating() << std::endl;

	std::string text = stream.str();
	return text;
}