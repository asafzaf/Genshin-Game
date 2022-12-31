#include <iostream>
#include "Player.h"
#include "LegendaryCharacter.h"
#include "EpicCharacter.h"

using namespace std;

Player::Player() {
	cout << "Pease write your user name: ";
	char* tempUsername = new char[20];
	cin >> tempUsername;
	int len = strlen(tempUsername);
	m_userName = new char[len + 1];
	strncpy(m_userName, tempUsername, len);

	m_activeCharacters = new Character * [4];
	m_dataCharacters = new Character * [10];
}

Player::~Player() {
	delete m_userName;
	delete[] m_activeCharacters;
	int i = 0;
	while (m_dataCharacters[i] != nullptr) {
		delete m_dataCharacters[i++];
	}
	delete[] m_dataCharacters;
}

void Player::addCharacter() {
	cout << "Please write your character name: ";
	char* temp_name = new char[20];
	cin >> temp_name;


	const char* location = chooselocation();


	Element element = chooseElement();
	Weapon weapon_choose = chooseANDchangeWeapon();

	cout << "Please write weapon name: ";
	char* weapon_name = new char[20];
	cin >> weapon_name;

	int stars = 0;
	do {
		cout << "Please choose no. of stars:" << endl
			<< "* \n** \n*** \n**** \n*****" << endl
			<< ">> ";
		cin >> stars;
	} while (stars > 5 || stars < 1);

	if (stars == 5) {
		cout << "Please enter signeture weapon name: ";
		char* signweapname = new char[20];
		cin >> signweapname;
		m_dataCharacters[num_of_dataChars++] = new LegendaryCharacter(temp_name, location, element, weapon_choose, weapon_name, stars, signweapname);
	}
	
	else if (stars == 4) {
		m_dataCharacters[num_of_dataChars++] = new EpicCharacter(temp_name, location, element, weapon_choose, weapon_name, stars);
	}

	else {
		m_dataCharacters[num_of_dataChars++] = new Character(temp_name, location, element, weapon_choose, weapon_name, stars);
	}
	return;
}

const char* chooselocation() {
	int loc_choose = 0;
	do {
		cout << "Choose location: " << endl
			<< "1- Europe" << endl
			<< "2- Asia" << endl
			<< "3- Mars" << endl
			<< "4- Moon" << endl
			<< "5- Saturn" << endl
			<< ">> ";
		cin >> loc_choose;
	} while (loc_choose > 5 || loc_choose < 1);

	
	switch (loc_choose)
	{
	case 1:
		const char* location = "Europe";
		return location;
		break;
	case 2:
		const char* location = "Asia";
		return location;
		break;
	case 3:
		const char* location = "Mars";
		return location;
		break;
	case 4:
		const char* location = "Moon";
		return location;
		break;
	case 5:
		const char* location = "Saturn";
		return location;
		break;
	default:
		const char* location = "null";
		return location;
		break;
	}
}

Element Player::chooseElement() {

	int type_choose = 0;
	do {
		cout << "Please choose type of character: " << endl
			<< "************************" << endl
			<< "1- Ameno\t 5- Electro" << endl
			<< "2- Pyro\t 6- Geo" << endl
			<< "3- Cyro\t 7- Dendro" << endl
			<< "4- Hydro" << endl
			<< "************************" << endl
			<< ">> ";
		cin >> type_choose;
	} while (type_choose > 7 || type_choose < 1);

	switch (type_choose)
	{
	case 1:
		return Ameno;
	case 2:
		return Pyro;
	case 3:
		return Cyro;
	case 4:
		return Hydro;
	case 5:
		return Electro;
	case 6:
		return Geo;
	case 7:
		return Dendro;
	default:
		return Uninitialized;
		break;
	}
}