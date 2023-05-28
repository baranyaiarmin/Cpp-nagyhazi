#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Players.h"

class Team {
	std::string teamName;
	std::vector <Player> team;
	std::vector <std::string> positions;
	static const int MaxPlayerCount = 5;
	int playerCount;
	int teamRating;
public:
	Team() : teamName(), team(), positions(), playerCount(0), teamRating(0) {}
	Team(std::string pTeamName) : teamName(pTeamName), team(), positions(), playerCount(0), teamRating(0) {}
	std::string getTeamName() { return teamName; }
	void setTeamName(std::string pTeamName) { this->teamName = pTeamName; }
	std::string getPositions();

	int getPlayerCount() { return playerCount; }
	int getTeamRating() const { return teamRating; }
	static const int getMaxPlayerCount() { return MaxPlayerCount; }
	bool add(const Player&);
	bool add(const Player&, std::string);
	std::string toString();
	~Team() {}
};