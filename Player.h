#pragma once

// This project made by Asaf Zafrir (205929029)

#include "Character.h"

//---        Player.h          ---//

class Player {
private:
	char* m_userName;
	Character** m_activeCharacters;
	Character** m_dataCharacters;
	int m_num_of_dataChars;
public:
	Player(); // Initializing player.
	~Player(); // distruct player and all of the data.

	//---      Methods      ---//
	void addCharacter(); // Adding new character to data.
	Character* selectCharacter(); // Select character from data and returns pointer.
	void setCharacterToActive(); // Set an active slot with pointer to data character.
	void changeWeapon(); // Set new weapon type to character.
	Weapon chooseWeapon(); // Print options and return weapon value by choice.
	const char* chooselocation(); // Print options and return the location name.
	Element chooseElement(); // Print options and return element value by choice.
	void evaluate(); // Evaluate all active characters as a team.
	void printLocationResaults(int* locationArr); // Sub-function that printing from list the locations resaults for evaluating.
	void printElementsResaults(int* elementArr);// Sub-function that printing from list the elements resaults for evaluating.
	void printWeaponsActives(); // Sub-function that printing the weapons uses for evaluating.
	const char* indexElementToText(int index); // Converting the type of element to text.



	//--- Getters & setters ---//
	char* getUserName() { return m_userName; }
	void setUserName(char* userName) { m_userName = userName; }

	Character** getActiveCharacter() { return m_activeCharacters; }
	Character** getDataCharacter() { return m_dataCharacters; }

	int getNumOfDataChars() { return m_num_of_dataChars; }
};
