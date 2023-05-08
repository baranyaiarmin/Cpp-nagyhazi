#include <iostream>
#include <string>
#include <sstream>
#include "Players.h"

std::string Player::toString()
{
	std::stringstream stream;
	stream << "Name: " << name << std::endl << "Team: " << team << std::endl << "Height: " << height << std::endl << "Age: " << age << std::endl;

	std::string text = stream.str();
	return text;
}

std::string PointGuard::toString()
{
	std::stringstream stream;
	stream << "Name: " << getName() << std::endl << "Team: " << getTeam() << std::endl << "Position: " << position << std::endl << "Height: " << getHeight() << std::endl << "Age: " << getAge() << std::endl;

	std::string text = stream.str();
	return text;
}

std::string ShootingGuard::toString()
{
	std::stringstream stream;
	stream << "Name: " << getName() << std::endl << "Team: " << getTeam() << std::endl << "Position: " << position << std::endl << "Height: " << getHeight() << std::endl << "Age: " << getAge() << std::endl;

	std::string text = stream.str();
	return text;
}

std::string SmallForward::toString()
{
	std::stringstream stream;
	stream << "Name: " << getName() << std::endl << "Team: " << getTeam() << std::endl << "Position: " << position << std::endl << "Height: " << getHeight() << std::endl << "Age: " << getAge() << std::endl;

	std::string text = stream.str();
	return text;
}

std::string PowerForward::toString()
{
	std::stringstream stream;
	stream << "Name: " << getName() << std::endl << "Team: " << getTeam() << std::endl << "Position: " << position << std::endl << "Height: " << getHeight() << std::endl << "Age: " << getAge() << std::endl;

	std::string text = stream.str();
	return text;
}

std::string Center::toString()
{
	std::stringstream stream;
	stream << "Name: " << getName() << std::endl << "Team: " << getTeam() << std::endl << "Position: " << position << std::endl << "Height: " << getHeight() << std::endl << "Age: " << getAge() << std::endl;

	std::string text = stream.str();
	return text;
}