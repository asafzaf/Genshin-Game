// This project made by Asaf Zafrir (205929029)

#include <iostream>
#include "Character.h"
#include "Player.h"

using namespace std;

void main() {

	Player* player = new Player();

	int choice = 5;
	while (choice > 4 || choice < 0) {
		// menu print...
		
		cin >> choice;

		switch (choice) {
		case 0:
			return;
		case 1:
			player->addCharacter();
			choice = 5;
			break;
		case 2:

			choice = 5;
			break;
		case 3:
			choice = 5;
			break;
		case 4:
			choice = 5;
			break;
		default:
			cout << "Invalid choice! please try again..." << endl;
			choice = 5;
		}
	}
	return;
}