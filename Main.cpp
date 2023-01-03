// This project made by Asaf Zafrir (205929029)

#include <iostream>
#include "Character.h"
#include "Player.h"

using namespace std;

int main() { // main process.

	cout << "*****************************" << endl
		<< "Hello and welcome to Genshin!" << endl
		<< "*****************************" << endl;

	Player* player = new Player(); // creating new player (User).

	int choice = -1;
	while (choice > 4 || choice < 0) {

		//Main menu
		cout << "************************" << endl
			<< "\tHello " << player->getUserName() << "!" << endl
			<< "************************" << endl
			<< "Please Choose an option:" << endl
			<< "1- Add data character" << endl
			<< "2- Change weapon" << endl
			<< "3- Set active character" << endl
			<< "4- Print evaluate" << endl
			<< ">> ";

		cin >> choice;

		switch (choice) {
		case 0:
			cout << "Bye!";
			return 0;
		case 1:
			player->addCharacter(); // function for add caracter to data.
			choice = -1;
			break;
		case 2:
			player->changeWeapon(); // function for change weapon for character
			choice = -1;
			break;
		case 3:
			player->setCharacterToActive(); // function for set one of the data characters to active.
			choice = -1;
			break;
		case 4:
			player->evaluate(); // function for evaluate active characters as a team.
			choice = -1;
			break;
		default:
			cout << "Invalid choice! please try again..." << endl;
			choice = -1;
			break;
		}
	}
}