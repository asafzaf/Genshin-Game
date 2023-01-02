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
	void addCharacter();
	Character* selectCharacter();
	void setCharacterToActive();
	void changeWeapon();
	Weapon chooseWeapon();
	const char* chooselocation();
	Element chooseElement();
	void evaluate();
	void printLocationResaults(int* locationArr);
	void printElementsResaults(int* elementArr);
	void printWeaponsActives();


	//--- Getters & setters ---//
	char* getUserName() { return m_userName; }
	void setUserName(char* userName) { m_userName = userName; }

	Character** getActiveCharacter() { return m_activeCharacters; }
	Character** getDataCharacter() { return m_dataCharacters; }

	int getNumOfDataChars() { return m_num_of_dataChars; }
};
