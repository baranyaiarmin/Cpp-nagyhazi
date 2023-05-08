#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Players.h"

class Team {
	std::string teamName;
	std::vector <Player> team;
	std::vector <std::string> positions;
	static const int MaxPlayerCount = 5;
	int playerCount;
public:
	Team() : teamName(), team(), positions(), playerCount(0) {}
	Team(std::string pTeamName) : teamName(pTeamName), team(), positions(), playerCount(0) {}
	std::string getTeamName() { return teamName; }
	std::string getPositions();
	int getPlayerCount() { return playerCount; }
	const int getMaxPlayerCount() const { return MaxPlayerCount; }
	void add(const Player&);
	std::string toString();
};