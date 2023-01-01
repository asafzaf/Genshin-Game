// This project made by Asaf Zafrir (205929029)

#include <iostream>
#include "Character.h"
#include "Player.h"

using namespace std;

int main() {

	Player* player = new Player();

	int choice = -1;
	while (choice > 5 || choice < 0) {

		//Main menu
		cout << "************************" << endl
			<< "Hello " << player->getUserName() << "!" << endl
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
			player->addCharacter();
			choice = -1;
			break;
		case 2:
			player->changeWeapon();
			choice = -1;
			break;
		case 3:
			player->setCharacterToActive();
			choice = -1;
			break;
		case 4:
			player->evaluate();
			choice = -1;
			break;
		case 5: // for tests
			choice = -1;
			cout << player->getUserName() << endl;
		default:
			cout << "Invalid choice! please try again..." << endl;
			choice = -1;
		}
	}
	return 0;
}