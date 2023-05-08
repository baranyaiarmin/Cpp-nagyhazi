#include <iostream>
#include <string>
#pragma once

class Player{
	std::string name;
	std::string team;
	int height;
	int age;
public:
	Player() : name(), team(), height(0), age(0) {}
	Player(std::string pName, std::string pTeam, int pHeight, int pAge) : name(pName), team(pTeam), height(pHeight), age(pAge) {}
	std::string getName() const { return name; }
	std::string getTeam() const { return team; }
	int getHeight() const {  return height; }
	int getAge() const { return age; }
	virtual std::string toString();
	virtual std::string getPosition() const { return "Not good"; };
};

class PointGuard : public Player{
	std::string position;
public:
	PointGuard() : Player(), position("Point Guard") {}
	PointGuard(std::string pName, std::string pTeam, int pHeight, int pAge) : Player(pName, pTeam, pHeight, pAge), position("Point Guard") {}
	std::string getPosition() const { return position; }
	std::string toString();
};

class ShootingGuard : public Player {
	std::string position;
public:
	ShootingGuard() : Player(), position("Shooting Guard") {}
	ShootingGuard(std::string pName, std::string pTeam, int pHeight, int pAge) : Player(pName, pTeam, pHeight, pAge), position("Shooting Guard") {}
	std::string getPosition() const { return position; }
	std::string toString();
};

class SmallForward : public Player {
	std::string position;
public:
	SmallForward() : Player(), position("Small Forward") {}
	SmallForward(std::string pName, std::string pTeam, int pHeight, int pAge) : Player(pName, pTeam, pHeight, pAge), position("Small Forward") {}
	std::string getPosition() const { return position; }
	std::string toString();
};

class PowerForward : public Player {
	std::string position;
public:
	PowerForward() : Player(), position("Power Forward") {}
	PowerForward(std::string pName, std::string pTeam, int pHeight, int pAge) : Player(pName, pTeam, pHeight, pAge), position("Power Forward") {}
	std::string getPosition() const { return position; }
	std::string toString();
};

class Center : public Player {
	std::string position;
public:
	Center() : Player(), position("Center") {}
	Center(std::string pName, std::string pTeam, int pHeight, int pAge) : Player(pName, pTeam, pHeight, pAge), position("Center") {}
	std::string getPosition() const { return position; }
	std::string toString();
};