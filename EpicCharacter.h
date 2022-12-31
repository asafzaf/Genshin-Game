#pragma once

// This project made by Asaf Zafrir (205929029)

#include "Character.h"

//---        EpicCharacter.h          ---//

class EpicCharacter : public Character {
public:
	EpicCharacter(char* name, const char* location, Element E_type, Weapon W_type, char* eq_wea, int star);
	int Attack();
};