#pragma once

// This project made by Asaf Zafrir (205929029)

#include "Character.h"

//---        LegendaryCharacter.h          ---//

class LegendaryCharacter : public Character {
private:
	char* m_signatureWeapon;
public:
	LegendaryCharacter(char* name, const char* location, Element E_type, Weapon W_type, char* eq_wea, int star, char* si);
	void printCharacter();
	int Attack();

	char* getSignatureWeapon() { return m_signatureWeapon; }
};