#pragma once
#include "Players.h"

class Center : public Player {
	std::string position;
public:
	Center() : Player(), position("Center") {}
	Center(std::string pName, std::string pTeam, int pHeight, int pAge, int pRating) : Player(pName, pTeam, pHeight, pAge, pRating), position("Center") {}
	std::string getPosition() const { return position; }
	std::string toString();
};