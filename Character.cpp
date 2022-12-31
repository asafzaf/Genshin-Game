#include <iostream>
#include "Character.h"

Character::Character(char* name, const char* location, Element E_type, Weapon W_type, char* eq_wea, int star) {
	int namelen = strlen(name);
	m_name = new char[namelen + 1];
	strncpy(m_name, name, namelen);

	m_location = location;

	m_type = E_type;
	m_weaponType = W_type;

	int weaponlen = strlen(eq_wea);
	m_equippedWeapon = new char[weaponlen + 1];
	strncpy(m_equippedWeapon, eq_wea, weaponlen);

	m_stars = star;
}
Character::~Character() {
	delete m_name;
	delete m_location;
	delete m_equippedWeapon;
}

//---      Methods      ---//
int Character::Attak() {
	return 10;
}
int EditWeapon(char* weapon); // ??