#pragma once
#include "Players.h"

class PowerForward : public Player {
	std::string position;
public:
	PowerForward() : Player(), position("Power Forward") {}
	PowerForward(std::string pName, std::string pTeam, int pHeight, int pAge, int pRating) : Player(pName, pTeam, pHeight, pAge, pRating), position("Power Forward") {}
	std::string getPosition() const { return position; }
	std::string toString();
};