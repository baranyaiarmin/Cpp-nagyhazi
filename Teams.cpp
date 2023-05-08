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

void Team::add(const Player& player)
{
    if (playerCount + 1 > MaxPlayerCount)
    {
        std::cout << "Team is full!" << std::endl << std::endl;
        return;
    }
    for (int i = 0; i < playerCount; i++)
    {
        if (player.getPosition() == positions[i])
        {
            std::cout << "A player from that position (" << player.getPosition() << ") already exists in this team!" << std::endl << std::endl;
            return;
        }
    }
    playerCount++;
    team.push_back(player);
    positions.push_back(player.getPosition());
    //std::cout << player.getPosition() << std::endl << std::endl;
}

std::string Team::toString()
{
    std::stringstream stream;
    stream << "Teamname: " << teamName << std::endl << "Playercount: " << playerCount << std::endl;
    
    for (int i = 0; i < playerCount; i++)
    {
        stream << "Player: " << team[i].getName() << "(" << positions[i] << ")" << std::endl;
    }

    std::string string = stream.str();
    return string;
}
