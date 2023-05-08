#include <iostream>
#include <string>
#include "Players.h"
#include "Teams.h"

using namespace std;

int main()
{
	//jatekosok tesztelés
	PointGuard StephenCurry("Stephen Curry", "Golden State Warriors", 188, 35);
	//cout << StephenCurry.toString() << endl;
	
	Center NikolaJokic("Nikola Jokic", "Denver Nuggets", 211, 28);

	PointGuard DeAaronFox("De'Aaron Fox", "Sacramento Kings", 190, 25);

	Center DomantasSabonis("Domantas Sabonis", "Sacramento Kings", 216, 27);

	Team SacramentoKings("Sacramento Kings");
	cout << SacramentoKings.toString() << endl;

	SacramentoKings.add(DeAaronFox);
	SacramentoKings.add(DomantasSabonis);
	SacramentoKings.add(StephenCurry);
	SacramentoKings.add(NikolaJokic);

	cout << SacramentoKings.toString() << endl;

	cout << SacramentoKings.getPositions() << endl;
}