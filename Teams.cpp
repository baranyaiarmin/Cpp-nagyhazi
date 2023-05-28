#include <iostream>
#include <string>
#include <sstream>
#include "Teams.h"

std::string Team::getPositions()
{
    std::stringstream stream;
    for (int i = 0; i < playerCount; i++)
    {
        
        stream << positions[i] << std::endl;
    }
    std::string text = stream.str();
    return text;
}

bool Team::add(const Player& player)
{
    if (playerCount + 1 > this->getMaxPlayerCount())
    {
        std::cout << "Team is full!" << std::endl << std::endl;
        return false;
    }
    for (int i = 0; i < playerCount; i++)
    {
        if (player.getPosition() == positions[i])
        {
            std::cout << "A player from that position (" << player.getPosition() << ") already exists in this team!" << std::endl << std::endl;
            return false;
        }
    }
    playerCount++;
    team.push_back(player);
    teamRating += player.getRating();
    positions.push_back(player.getPosition());
    return true;
}

bool Team::add(const Player& player, std::string positionOfPlayer)
{
    if (playerCount + 1 > this->getMaxPlayerCount())
    {
        std::cout << "Team is full!" << std::endl << std::endl;
        return false;
    }
    for (int i = 0; i < playerCount; i++)
    {
        if (positionOfPlayer == positions[i])
        {
            std::cout << std::endl << "A player from that position (" << positionOfPlayer << ") already exists in this team!" << std::endl << std::endl;
            return false;
        }
    }
    playerCount++;
    team.push_back(player);
    teamRating += player.getRating();
    positions.push_back(positionOfPlayer);
    return true;
    //std::cout << player.getPosition() << std::endl << std::endl;
}

std::string Team::toString()
{
    std::stringstream stream;
    stream << "Teamname: " << teamName << std::endl << "Playercount: " << playerCount << std::endl << "Teamrating: " << teamRating << std::endl;
    
    for (int i = 0; i < playerCount; i++)
    {
        stream << "Player: " << team[i].getName() << " (" << positions[i] << ")" << " from the " << team[i].getTeam() << std::endl;
    }

    std::string string = stream.str();
    return string;
}