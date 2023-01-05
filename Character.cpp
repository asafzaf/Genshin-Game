#include <iostream>
#include "Character.h"

using namespace std;

Character::Character(char* name, const char* location, Element E_type, Weapon W_type, char* eq_wea, int star) {
	int namelen = strlen(name);
	m_name = new char[namelen + 1];
	strcpy(m_name, name);

	m_location = location;

	m_type = E_type;
	m_weaponType = W_type;

	int weaponlen = strlen(eq_wea);
	m_equippedWeapon = new char[weaponlen + 1];
	strcpy(m_equippedWeapon, eq_wea);

	m_stars = star;
}
Character::~Character() {
	delete m_name;
	delete m_location;
	delete m_equippedWeapon;
}

//---      Methods      ---//
int Character::Attack() { // No need to explain.
	printWeaponsActive();
	return 10;
}

void Character::PrintCharacter() { // Printing character info in one line.
	int stars = getStars();
	cout << getName() << "\t"
		<< getLocation() << "\t"
		<< enumElementToText() << "\t"
		<< enumWeaponToText() << "\t"
		<< getEqWeapon() << "\t";
	for (int i = 0; i < stars; i++) {
		cout << "*";
	}
	cout << endl;
}

int Character::locationInNumber() { // Returning location as a number.
	const char* tempchar = getLocation();
	if (tempchar == "Europe") {
		return 0;
	}
	else if (tempchar == "Asia") {
		return 1;
	}
	else if (tempchar == "Mars") {
		return 2;
	}
	else if (tempchar == "Moon") {
		return 3;
	}
	else if (tempchar == "Saturn") {
		return 4;
	}
	else return -1;
}

const char* Character::enumElementToText() { // Returning the enum as a text.
	switch (m_type)
	{
	case Uninitialized:
		return "---";
		break;
	case Ameno:
		return "Ameno";
		break;
	case Pyro:
		return "Pyro";
		break;
	case Cyro:
		return "Pyro";
		break;
	case Hydro:
		return "Hydro";
		break;
	case Electro:
		return "Electro";
		break;
	case Geo:
		return "Gro";
		break;
	case Dendro:
		return "Dentro";
		break;
	default:
		return "Err";
		break;
	}
}

const char* Character::enumWeaponToText() { // Returning the enum as a text.
	switch (m_weaponType)
	{
	case unarmed:
		return "---";
		break;
	case Sword:
		return "Sword";
		break;
	case Polearm:
		return "Polearm";
		break;
	case Catalyst:
		return "Catalyst";
		break;
	case Claymore:
		return "Claymore";
		break;
	case Bow:
		return "Bow";
		break;
	default:
		return "Err";
		break;
	}
} 

void Character::printWeaponsActive() { // Sub-function that printing the weapons uses for evaluating.
	switch (m_weaponType)
	{
	case unarmed:
		cout << "Err" << endl << endl;
		break;
	case Sword:
		cout << getName() << " swing swiftly the sword." << endl << endl;
		break;
	case Polearm:
		cout << getName() << " agile with polearm." << endl << endl;
		break;
	case Catalyst:
		cout << getName() << " cast spells with catalyst." << endl << endl;
		break;
	case Claymore:
		cout << getName() << " swing the heavy claymore." << endl << endl;
		break;
	case Bow:
		cout << getName() << " shot from afar with the bow." << endl << endl;
		break;
	default:
		cout << "Err" << endl << endl;
		break;
	}
}