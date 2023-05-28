#include <iostream>
#include <string>
#pragma once

class Player{
	std::string name;
	std::string team;
	int height;
	int age;
	int rating;
public:
	Player() : name(), team(), height(0), age(0), rating(0) {}
	Player(std::string pName, std::string pTeam, int pHeight, int pAge, int pRating) : name(pName), team(pTeam), height(pHeight), age(pAge), rating(pRating) {}
	std::string getName() const { return name; }
	std::string getTeam() const { return team; }
	int getHeight() const {  return height; }
	int getAge() const { return age; }
	int getRating() const { return rating; }
	virtual std::string toString();
	virtual std::string getPosition() const { return "Not good"; };
	~Player() {}
};