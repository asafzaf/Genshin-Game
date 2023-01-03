#include <iostream>
#include "LegendaryCharacter.h"

using namespace std;

LegendaryCharacter::LegendaryCharacter(char* name, const char* location, Element E_type, Weapon W_type, char* eq_wea, int star, char* signeture) : Character(name, location, E_type, W_type, eq_wea, star) {
	int signlen = strlen(signeture);
	m_signatureWeapon = new char[signlen + 1];
	strcpy(m_signatureWeapon, signeture);
}

void LegendaryCharacter::printCharacter() { // Special Print with signature weapon.
	cout << getName() << "\t"
		<< getLocation() << "\t"
		<< getElementType() << "\t"
		<< getWeaponType() << "\t"
		<< getEqWeapon() << "\t"
		<< getStars() << "\t"
		<< getSignatureWeapon() << endl;
}

int LegendaryCharacter::Attack() { // No need to explain.
	return 40;
}