#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <random>
#include "Players.h"
#include "Teams.h"
#include "PointGuard.h"
#include "ShootingGuard.h"
#include "SmallForward.h"
#include "PowerForward.h"
#include "Center.h"

using namespace std;

extern void pickTeam(vector<Team> allTeams, Team& yourTeam); //to tell the compiler the function exists

int getRandomNumber(int x, int y) // get a random number in a certain range
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(x, y);

    return dis(gen);
}

bool getAllTeams(vector<Team>& allTeams) {
    string errorstring = "teams.txt file not found!";
    try
    {
    ifstream file("teams.txt"); //
    if (!file.is_open()) 
        { 
          throw errorstring;
        }

    if (file) {
        string line;
        while (getline(file, line)) {
            Team team(line);
            allTeams.push_back(team);
        }
    }

    file.close();
    return true;
}
    catch (string error)
    {
        cout << error << endl;
        return false;
    }
}

bool getAllPlayers(vector<Team>& allTeams, vector<Player>& allPlayers, vector<string>& allPositions) {
    string errorstring = "players.txt file not found!";
    string errorstring2 = "Can not parse the line!";
    try {
        ifstream file("players.txt");

        if (!file) 
        {
            throw errorstring;
        }

        string line;
        while (getline(file, line)) {
            istringstream iss(line);

            string position;
            string name;
            string team;
            int height;
            int age;
            int rating;

            if (getline(iss, position, ',')) {
                getline(iss, name, ',');
                getline(iss, team, ',');

                // Convert values to integers
                iss >> height;
                iss.ignore();  // Ignore the comma
                iss >> age;
                iss.ignore();  // Ignore the comma
                iss >> rating;
                allPlayers.push_back(Player(name, team, height, age, rating));
                allPositions.push_back(position);
            }
            else {
                throw errorstring2;
            }

            if (position == "Point Guard")
            {
                PointGuard player(name, team, height, age, rating);
                for (int i = 0; i < allTeams.size(); i++)
                {
                    if (allTeams[i].getTeamName() == team)
                        allTeams[i].add(player);
                }
            }
            else if (position == "Shooting Guard")
            {
                ShootingGuard player(name, team, height, age, rating);
                for (int i = 0; i < allTeams.size(); i++)
                {
                    if (allTeams[i].getTeamName() == team)
                        allTeams[i].add(player);
                }
            }
            else if (position == "Small Forward")
            {
                SmallForward player(name, team, height, age, rating);
                for (int i = 0; i < allTeams.size(); i++)
                {
                    if (allTeams[i].getTeamName() == team)
                        allTeams[i].add(player);
                }
            }
            else if (position == "Power Forward")
            {
                PowerForward player(name, team, height, age, rating);
                for (int i = 0; i < allTeams.size(); i++)
                {
                    if (allTeams[i].getTeamName() == team)
                        allTeams[i].add(player);
                }
            }
            else if (position == "Center")
            {
                Center player(name, team, height, age, rating);
                for (int i = 0; i < allTeams.size(); i++)
                {
                    if (allTeams[i].getTeamName() == team)
                        allTeams[i].add(player);
                }
            }
            else
            {
                cout << "This position does not exist!" << endl;
            }
        }

        file.close();
        return true;
    }
    catch (string errorstring)
    {
        cout << errorstring << endl;
        return false;
    }
}

string getPickedTeam(vector<Team> allTeams, Team& yourTeam)
{
    bool ifHelp = false;
    string answer;
    while(!ifHelp)
    {
        cout << "What team do you want to pick? (type 'help' for help): ";
        getline(cin >> ws, answer);
        if (answer == "help")
        {
            cout << "You can choose from the following teams: " << endl;
            for (int i = 0; i < allTeams.size(); i++)
            {
                cout << "- " << allTeams[i].getTeamName() << endl;
            }
        }
        else
            ifHelp = true;
    }
    return answer;
}

void playersHelp(string help, vector<Player> allPlayers, vector<string> allPositions)
{
    if (help == "pghelp")
    {
        for (int i = 0; i < allPlayers.size(); i++)
        {
            if (allPositions[i] == "Point Guard")
                cout << "- " << allPlayers[i].getName() <<" (Rating: " << allPlayers[i].getRating() << ")" << " from the " << allPlayers[i].getTeam() << endl;
        }
    }
    else if (help == "sghelp")
    {
        for (int i = 0; i < allPlayers.size(); i++)
        {
            if (allPositions[i] == "Shooting Guard")
                cout << "- " << allPlayers[i].getName() << " (Rating: " << allPlayers[i].getRating() << ")" << " from the " << allPlayers[i].getTeam() << endl;
        }
    }
    else if (help == "sfhelp")
    {
        for (int i = 0; i < allPlayers.size(); i++)
        {
            if (allPositions[i] == "Small Forward")
                cout << "- " << allPlayers[i].getName() << " (Rating: " << allPlayers[i].getRating() << ")" << " from the " << allPlayers[i].getTeam() << endl;
        }
    }
    else if (help == "pfhelp")
    {
        for (int i = 0; i < allPlayers.size(); i++)
        {
            if (allPositions[i] == "Power Forward")
                cout << "- " << allPlayers[i].getName() << " (Rating: " << allPlayers[i].getRating() << ")" << " from the " << allPlayers[i].getTeam() << endl;
        }
    }
    else if (help == "chelp")
    {
        for (int i = 0; i < allPlayers.size(); i++)
        {
            if (allPositions[i] == "Center")
                cout << "- " << allPlayers[i].getName() << " (Rating: " << allPlayers[i].getRating() << ")" << " from the " << allPlayers[i].getTeam() << endl;
        }
    }
    cout << endl;
}

void pickPlayers(Team& yourTeam, vector<Player> allPlayers, vector<string> allPositions)
{
    bool added = false; //1 - succesfully added player, 0 - a player from this position already exists on the team
    bool exists = false; // see if the entered player exists
    while (yourTeam.getPlayerCount() < 5)
    {
        bool ifHelp = false;
        exists = false;
        string player;
        while (!ifHelp)
        {
            cout << "Pick a player (type 'help' for help commands): ";
            getline(cin >> ws, player);
            if (player == "help")
            {
                cout << "- 'pghelp' for Point Guards\n- 'sghelp' for Shooting Guards\n- 'sfhelp' for Small Forwards\n- 'pfhelp' for Power Forwards\n- 'chelp' for Centers" << endl;
            }
            else if (player == "pghelp" || player == "sghelp" || player == "sfhelp" || player == "pfhelp" || player == "chelp")
                playersHelp(player, allPlayers, allPositions);
            else
                ifHelp = true;
        }

        for (int i = 0; i < allPlayers.size(); i++)
        {
            if (allPlayers[i].getName() == player)
            {
                exists = true;
                added = yourTeam.add(allPlayers[i], allPositions[i]); //only print out the team if a player was successfully added
                break;
            }
        }
        if (added)
            cout << endl << yourTeam.toString();
        if (!exists)
            cout << endl << "This player (" << player << ") does not exist!" << endl << endl;
    }
}

bool createTeam(Team& yourTeam, vector<Player> allPlayers, vector<string> allPositions, vector<Team> allTeams)
{
    bool isAnswerOk = false;
    string answer;

    while (!isAnswerOk)
    {
        cout << "Do you want to create your own team?(yes/no): ";
        cin >> answer;

        if (answer == "no" || answer == "NO" || answer == "n")
            return false;
        else if (answer == "yes" || answer == "YES" || answer == "y")
            isAnswerOk = true;
    }
    bool success = false;
    bool alreadyExists = false;
    string teamName;
    while (!success)
    {
        alreadyExists = false;
        cout << "What is the name of your team?: ";
        getline(cin >> ws, teamName);
        for (int i = 0; i < allTeams.size(); i++)
        {
            if (allTeams[i].getTeamName() == teamName)
            {
                cout << endl << "Please don't use this team name (" << teamName << ") because there is already a team with this name!" << endl << endl;
                alreadyExists = true;
            }
        }
        if (!alreadyExists)
            success = true;
    }
    yourTeam.setTeamName(teamName);
    cout << "Your Team name is : " << yourTeam.getTeamName() << endl;
    pickPlayers(yourTeam, allPlayers, allPositions);
    return true;
}

void pickTeam(vector<Team> allTeams, Team& yourTeam)
{
    int szamlalo = 0;
    string answer = getPickedTeam(allTeams, yourTeam);
    for (int i = 0; i < allTeams.size(); i++)
    {
        if (allTeams[i].getTeamName() == answer)
        {
            szamlalo++;
            yourTeam = allTeams[i];
            cout << yourTeam.toString();
            return;
        }        
    }
    if (szamlalo == 0) 
    {
        cout << "This team (" << answer << ") does not exist!" << endl;
        pickTeam(allTeams, yourTeam);
    }
}

bool playMatches(Team& yourTeam, Team& opponentTeam)
{
    string temp;
    int yourPoints = 0;
    int opponentPoints = 0;
    int odds = (int)((1 - ((float)(opponentTeam.getTeamRating() - 200) / (float)(yourTeam.getTeamRating() - 200)) + 0.5) * 100);
    cout << "Your opponent is the " << opponentTeam.getTeamName() << "!" << endl << "Your chances at winning: " << odds << "%" << endl;
    cout << endl << "Press enter for the first match!";
    getline(cin, temp);
    while (true)
    {
        if (getRandomNumber(1, 100) <= odds)
            yourPoints++;
        else
            opponentPoints++;
        cout << "Current standing: " << yourPoints << "-" << opponentPoints << endl;
        if (opponentPoints >= 4)
            return false;
        if (yourPoints >= 4)
        {
            cout << endl << "You won the series against the " << opponentTeam.getTeamName() << "!" << endl;
            cout << endl << "Press enter to continue!";
            getline(cin, temp);
            return true;
        }
        cout << "Press enter for the next match!";
        getline(cin, temp);
    }
}

void playOffs(vector<Team>& allTeams, Team& yourTeam)
{
    bool ifLost = false;
    int getRidOf;
    int opponent;
    Team opponentTeam;

    //(15 + 1(you) contenders)
    cout << endl << "PLAYOFFS FIRST ROUND!" << endl << endl;
    for (int i = 0; i < 14; i++) // remove 14 teams, so that there are 16 teams left in the playoffs
    {
        getRidOf = getRandomNumber(1, allTeams.size()-1);
        allTeams.erase(allTeams.begin() + getRidOf);
    }
    
    opponent = getRandomNumber(1, allTeams.size());
    opponentTeam = allTeams[opponent-1];

    ifLost = playMatches(yourTeam, opponentTeam);

    if (!ifLost)
    {
        cout << endl <<"You lost to the " << opponentTeam.getTeamName() << " in the first round of the playoffs!" << endl;
        return;
    }

    // (7 + 1(you) contenders)
    cout << endl <<"PLAYOFFS SECOND ROUND!" << endl << endl;

    allTeams.erase(allTeams.begin() + opponent-1);

    for (int i = 0; i < 7; i++) // remove 7 teams(plus your opponent before), so that there are 8 teams left in the playoffs
    {
        getRidOf = getRandomNumber(1, allTeams.size() - 1);
        allTeams.erase(allTeams.begin() + getRidOf);
    }

    opponent = getRandomNumber(1, allTeams.size());
    opponentTeam = allTeams[opponent-1];

    ifLost = playMatches(yourTeam, opponentTeam);

    if (!ifLost)
    {
        cout << endl << "You lost to the " << opponentTeam.getTeamName() << " in the second round of the playoffs!" << endl;
        return;
    }
    
    // (3 + 1(you) contenders)
    cout << endl << "CONFERENCE FINALS!" << endl << endl;
    
    allTeams.erase(allTeams.begin() + opponent-1);

    for (int i = 0; i < 3; i++) // remove 3 teams(plus your opponent before), so that there are 4 teams left in the playoffs
    {
        getRidOf = getRandomNumber(1, allTeams.size() - 1);
        allTeams.erase(allTeams.begin() + getRidOf);
    }

    opponent = getRandomNumber(1, allTeams.size());
    opponentTeam = allTeams[opponent-1];

    ifLost = playMatches(yourTeam, opponentTeam);

    if (!ifLost)
    {
        cout << endl << "You lost to the " << opponentTeam.getTeamName() << " in the conference finals!" << endl;
        return;
    }

    // (1 + 1(you) contenders)
    cout << endl << "FINALS!" << endl << endl;

    allTeams.erase(allTeams.begin() + opponent-1);

    for (int i = 0; i < 1; i++) // remove 1 teams(plus your opponent before), so that there are 2 teams left in the playoffs
    {
        getRidOf = getRandomNumber(1, allTeams.size() - 1);
        allTeams.erase(allTeams.begin() + getRidOf);
    }

    opponent = getRandomNumber(1, allTeams.size());
    opponentTeam = allTeams[opponent-1];

    ifLost = playMatches(yourTeam, opponentTeam);

    if (!ifLost)
    {
        cout << endl << "You lost to the " << opponentTeam.getTeamName() << " in the finals!" << endl;
        return;
    }
    
    cout << endl << "CONGRATULATIONS!!\nYou won the playoffs, and the championship with the following team: " << endl;
    cout << yourTeam.toString();
}

int main()
{
    vector<Player> allPlayers; //all players vector
    vector<string> allPositions; //all positions of players vector
    vector<Team> allTeams; //all teams vector

    bool gotTeams;

    gotTeams = getAllTeams(allTeams); //get all Teams from the teams.txt file into the allTeams vector
    if (!gotTeams)
        return -1;

    bool gotPlayers;

    gotPlayers = getAllPlayers(allTeams, allPlayers, allPositions); //get all Players from the players.txt file into the allPlayers vector
    if (!gotPlayers)
        return -1;


    Team yourTeam; //Your team

    bool createdTeam = createTeam(yourTeam, allPlayers, allPositions, allTeams);

    if (createdTeam)
    {
        int getRidOf = getRandomNumber(0, allTeams.size()); //if you created your own team there shouldn't be 31 teams left, only 30
        allTeams.erase(allTeams.begin() + getRidOf);
    }
    else
    {
        pickTeam(allTeams, yourTeam);
        for (vector<Team>::iterator i = allTeams.begin(); i != allTeams.end(); ++i) //if you didn't create a team, remove the picked team from the vector
        {
            if (i->getTeamName() == yourTeam.getTeamName())
            {
                allTeams.erase(i);
                break;
            }
        }
    }

    playOffs(allTeams, yourTeam);
}