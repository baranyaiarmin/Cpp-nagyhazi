#pragma once
#include "Players.h"

class PointGuard : public Player {
	std::string position;
public:
	PointGuard() : Player(), position("Point Guard") {}
	PointGuard(std::string pName, std::string pTeam, int pHeight, int pAge, int pRating) : Player(pName, pTeam, pHeight, pAge, pRating), position("Point Guard") {}
	std::string getPosition() const { return position; }
	std::string toString();
};