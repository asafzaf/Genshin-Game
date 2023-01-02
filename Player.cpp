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
	strcpy(m_userName, tempUsername);

	m_activeCharacters = new Character * [4];
	for (int i = 0; i < 4; i++) {
		m_activeCharacters[i] = nullptr;
	}
	m_dataCharacters = new Character * [10];
	for (int i = 0; i < 10; i++) {
		m_dataCharacters[i] = nullptr;
	}
	m_num_of_dataChars = 0;
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
	Weapon weapon_choose = chooseWeapon();

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
		m_dataCharacters[m_num_of_dataChars] = new LegendaryCharacter(temp_name, location, element, weapon_choose, weapon_name, stars, signweapname);
	}
	
	else if (stars == 4) {
		m_dataCharacters[m_num_of_dataChars] = new EpicCharacter(temp_name, location, element, weapon_choose, weapon_name, stars);
	}

	else {
		m_dataCharacters[m_num_of_dataChars] = new Character(temp_name, location, element, weapon_choose, weapon_name, stars);
	}
	m_num_of_dataChars++;
	cout << "Character added successfully! you have more " << (10 - m_num_of_dataChars) << " free spaces." << endl;
	return;
}

Character* Player::selectCharacter() {
	Character** temptr = getDataCharacter();
	cout << "*********************" << endl
		<< "data characters menu:" << endl
		<< "*********************" << endl;
	int i = 0;
	for ( int i = 0 ; i < m_num_of_dataChars; i++) {
		cout << i + 1 << "\t";
		temptr[i]->PrintCharacter();
	}
	int choose;
	cout << "Please enter number for character: ";
	cin >> choose;
	while (choose - 1 > m_num_of_dataChars) {
		cout << "Please select from list.. Try again.." << endl << ">> ";
		cin >> choose;
	}
	return temptr[choose-1];
}

void Player::setCharacterToActive() {
	if (getDataCharacter() == nullptr) {
		cout << "No Data Characters" << endl;
		return;
	}
	Character* selectedChar = selectCharacter();
	Character** tempActive = getActiveCharacter();
	for (int i = 0; i < 4; i++) {
		cout << i + 1 << "\t";
		if (tempActive[i] == nullptr) {
			cout << " *---FREE SPACE---*" << endl;
		}
		else tempActive[i]->PrintCharacter();
	}
	cout << "Please enter number for place in Active: ";
	int choose;
	cin >> choose;
	tempActive = getActiveCharacter();
	tempActive[choose - 1] = selectedChar;
}

void Player::changeWeapon() {
	Character** selected;
	Character* ptr = nullptr;
	int choose = 0;
	int char_choose = 0;
	while (choose < 1 || choose > 2) {
		cout << "*************" << endl
			<< "Change Weapon" << endl
			<< "*************" << endl
			<< "1- Active Characters" << endl
			<< "2- Data Characters" << endl
			<< ">> ";
		cin >> choose;
		if (choose == 1) {
			selected = getActiveCharacter();
			while (char_choose > 4 || char_choose < 1) {
				int count = 0;
				cout << "***********************" << endl
					<< "Active characters menu: " << endl
					<< "***********************" << endl;
				for (int i = 0; i < 4; i++) {
					if (selected[i] == nullptr) {
						continue;
					}
					else {
						cout << i + 1 << "\t";
						selected[i]->PrintCharacter();
						count++;
					}
				}
				if (count == 0) {
					cout << "No active characters!" << endl;
					choose = 0;
					break;
				}
				else {
					cout << "Please choose character: ";
					cin >> char_choose;
					if (char_choose > count) {
						char_choose = 0;
						cout << "Invalid number of character! Try again..." << endl;
					}
					ptr = selected[char_choose - 1];
				}
			}
		}
		else if (choose == 2) {
			ptr = selectCharacter();
		}
		else ptr = selectCharacter();
	}
	Weapon weap_choose = chooseWeapon();
	ptr->setWeaponType(weap_choose);
	cout << "Weapon has changed seccessfully" << endl;
}

Weapon Player::chooseWeapon() {
	int weapon_choose = 0;
		do {
			cout << "Choose Weapon: " << endl
				<< "1- Sword" << endl
				<< "2- Polearm" << endl
				<< "3- Catalyst" << endl
				<< "4- Claymore" << endl
				<< "5- Bow" << endl
				<< ">> ";

			cin >> weapon_choose;
		} while (weapon_choose > 5 || weapon_choose < 1);
	
		switch (weapon_choose)
		{
		case 1:
			return Sword;
		case 2:
			return Polearm;
		case 3:
			return Catalyst;
		case 4:
			return Claymore;
		case 5:
			return Bow;
		default:
			return unarmed;
		}
}

const char* Player::chooselocation() {
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
		return "Europe";
	case 2:
		return "Asia";
	case 3:
		return "Mars";
	case 4:
		return "Moon";
	case 5:
		return "Saturn";
	default:
		return "unlocate";
	}
}

Element Player::chooseElement() {

	int type_choose = 0;
	do {
		cout << "Please choose type of character: " << endl
			<< "************************" << endl
			<< "1- Ameno\t 5- Electro" << endl
			<< "2- Pyro\t\t 6- Geo" << endl
			<< "3- Cyro\t\t 7- Dendro" << endl
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
	}
}

void Player::evaluate() {
	int A_Location[6] = {0}, A_Type[8] = {0}, A_Weapon[6] = {0};
	int* Arr_locate = A_Location, * Arr_Elem = A_Type, * Arr_Weap = A_Weapon;
	Character** temp_char_array = getActiveCharacter();

	for (int i = 0; i < 4; i++) {
		if (temp_char_array[i] == nullptr) {
			cout << "*---FREE SPACE---*" << endl;
			continue;
		}
		temp_char_array[i]->PrintCharacter();
		A_Location[temp_char_array[i]->locationInNumber()]++;
		A_Type[temp_char_array[i]->getElementType()]++;
		A_Weapon[temp_char_array[i]->getWeaponType()]++;
	}

	for (int i = 0; i < 6; i++) {
		cout << A_Location[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 8; i++) {
		cout << A_Type[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 6; i++) {
		cout << A_Weapon[i] << " ";
	}
	cout << endl;

	printLocationResaults(Arr_locate);
	cout << endl << endl;
	printElementsResaults(Arr_Elem);
	cout << endl << endl;


	return;
}

void Player::printLocationResaults(int* locationArr) {
	for (int i = 1; i < 6; i++) {
		if (locationArr[i] > 1)
			cout << locationArr[i] << " characters from the same location:" << endl
			<< "Adding " << (locationArr[i]) * (10) << "% coordinaion!" << endl << endl;
	}
}

void Player::printElementsResaults(int* elementArr) {
	for (int i = 1; i < 8; i++) {
		if (elementArr[i] > 1)
			cout << elementArr[i] << " characters are" << elementEnumToText(i) << "elements:" << endl
			<< "Adding " << (elementArr[i])* (10) << "% " << elementEnumToText(i) << " power!" << endl << endl;
	}
	cout << "Passable Elements Reactions:" << endl;
	if (elementArr[1] > 0 && elementArr[3] > 0) { // Ameno + Cyro - combination.
		cout << "Blizzard" << endl;
	}
	if (elementArr[7] > 0 && elementArr[2] > 0) { // Dendro + Pyro - combination.
		cout << "Burn" << endl;
	}
	if (elementArr[6] > 0 && (elementArr[2] > 0 || elementArr[3] > 0 || elementArr[4] > 0 || elementArr[5] > 0)) { // Crystalize combination.
		cout << "Crystalize" << endl;
	}
	if (elementArr[6] > 0 && elementArr[1] > 0) { // Geo + Ameno - combination.
		cout << "Dust" << endl;
	}
	if (elementArr[5] > 0 && elementArr[4] > 0) { // Electro + Hydro - combination.
		cout << "Electro-Charged" << endl;
	}
	if (elementArr[3] > 0 && elementArr[4] > 0) { // Cyro + Hydro - combination.
		cout << "Frozen" << endl;
	}
	if (elementArr[6] > 0 && elementArr[2] > 0) { // Geo + Pyro - combination.
		cout << "Magma" << endl;
	}
	if (elementArr[3] > 0 && elementArr[2] > 0) { // Cryo + Pyro - combination.
		cout << "Melt" << endl;
	}
	if (elementArr[6] > 0 && elementArr[4] > 0) { // Geo + Hydro - combination.
		cout << "Mud" << endl;
	}
	if (elementArr[5] > 0 && elementArr[2] > 0) { // Electro + Pyro - combination.
		cout << "Overloaded" << endl;
	}
	if (elementArr[7] > 0 && elementArr[4] > 0) { // Dendro + Hydro - combination.
		cout << "Poison" << endl;
	}
	if (elementArr[6] > 0 && elementArr[3] > 0) { // Geo + Cryo - combination.
		cout << "Shatter" << endl;
	}
	if (elementArr[3] > 0 && elementArr[5] > 0) { // Cryo + Electro - combination.
		cout << "Superconduct" << endl;
	}
	if (elementArr[1] > 0 && (elementArr[3] > 0 || elementArr[5] > 0 || elementArr[4] > 0 || elementArr[2] > 0)) { // Swirl combination.
		cout << "Swirl" << endl;
	}
	if (elementArr[6] > 0 && elementArr[7] > 0) { // Geo + Dendro - combination.
		cout << "Thorn" << endl;
	}
	if (elementArr[4] > 0 && elementArr[2] > 0) { // Hydro + Pyro - combination.
		cout << "Vaporize" << endl;
	}
}

void Player::printWeaponsActives() {
	Character** tempchar = getActiveCharacter();
	for (int i = 0; i < 4; i++) {
		if (tempchar[i] == nullptr) {
			continue;
		}
		else {
			Weapon tempweap = tempchar[i]->getWeaponType();
			switch (tempweap)
			{
			case unarmed:
				cout << "Err";
				break;
			case Sword:
				cout << tempchar[i]->getName() << " swing swiftly the sword." << endl;
				break;
			case Polearm:
				cout << tempchar[i]->getName() << " agile with polearm." << endl;
				break;
			case Catalyst:
				cout << tempchar[i]->getName() << " cast spells with catalyst." << endl;
				break;
			case Claymore:
				cout << tempchar[i]->getName() << " swing the heavy claymore." << endl;
				break;
			case Bow:
				cout << tempchar[i]->getName() << " shot from afar with the bow." << endl;
				break;
			default:
				cout << "Err";
				break;
			}
		}
	}
}