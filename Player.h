#pragma once

// This project made by Asaf Zafrir (205929029)

#include "Character.h"

//---        Player.h          ---//

class Player {
private:
	char* m_userName;
	Character** m_activeCharacters;
	Character** m_dataCharacters;
	int num_of_dataChars;
public:
	Player(); // Initializing player.
	~Player(); // distruct player and all of the data.

	//---      Methods      ---//
	void addCharacter();
	Character* selectCharacter();
	Weapon chooseANDchangeWeapon();
	const char* chooselocation();
	Element chooseElement();

	//--- Getters & setters ---//
	char* getUserName() { return m_userName; }
	void setUserName(char* userName) { m_userName = userName; }
};
