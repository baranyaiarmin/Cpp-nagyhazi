#pragma once
#include "Players.h"

class SmallForward : public Player {
	std::string position;
public:
	SmallForward() : Player(), position("Small Forward") {}
	SmallForward(std::string pName, std::string pTeam, int pHeight, int pAge, int pRating) : Player(pName, pTeam, pHeight, pAge, pRating), position("Small Forward") {}
	std::string getPosition() const { return position; }
	std::string toString();
};