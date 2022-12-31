#include <iostream>
#include "LegendaryCharacter.h"

LegendaryCharacter::LegendaryCharacter(char* name, const char* location, Element E_type, Weapon W_type, char* eq_wea, int star, char* signeture) : Character(name, location, E_type, W_type, eq_wea, star) {
	int signlen = strlen(signeture);
	m_name = new char[signlen + 1];
	strncpy(m_signatureWeapon, signeture, signlen);
}