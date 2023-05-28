#pragma once
#include "Players.h"

class ShootingGuard : public Player {
	std::string position;
public:
	ShootingGuard() : Player(), position("Shooting Guard") {}
	ShootingGuard(std::string pName, std::string pTeam, int pHeight, int pAge, int pRating) : Player(pName, pTeam, pHeight, pAge, pRating), position("Shooting Guard") {}
	std::string getPosition() const { return position; }
	std::string toString();
};