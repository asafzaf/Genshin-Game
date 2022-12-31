#pragma once

// This project made by Asaf Zafrir (205929029)

#include "Enumerable.h"

//---        Character.h          ---//

class Character {
protected:
	char* m_name;
	const char* m_location;
	Element m_type;
	Weapon m_weaponType;
	char* m_equippedWeapon;
	int m_stars;
	
public:
	Character(char* name, const char* location, Element E_type, Weapon W_type, char* eq_wea, int star);
	~Character();

	//---      Methods      ---//
	virtual int Attak();
	int EditWeapon(char* weapon);

	//--- Getters & setters ---//
	char* getUserName() { return m_name; }
	void setUserName(char* name) { m_name = name; }

};