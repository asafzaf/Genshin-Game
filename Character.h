#pragma once

// This project made by Asaf Zafrir (205929029)

#include "Enumerable.h"

//---        Character.h          ---//

class Character {
protected:
	char* m_name;
	const char* m_location;
	enum Element m_type;
	enum Weapon m_weaponType;
	char* m_equippedWeapon;
	int m_stars;
	
public:
	Character(char* name, const char* location, Element E_type, Weapon W_type, char* eq_wea, int star);
	~Character();

	//---      Methods      ---//
	virtual int Attack(); // No need to explain.
	virtual void PrintCharacter(); // Printing character info in one line.
	int locationInNumber(); // Returning location as a number.
	const char* enumElementToText(); // Returning the enum as a text.
	const char* enumWeaponToText(); // Returning the enum as a text.

	//--- Getters & setters ---//
	char* getName() { return m_name; }
	void setName(char* name) { m_name = name; }

	const char* getLocation() { return m_location; }

	Element getElementType() { return m_type; }

	Weapon getWeaponType() { return m_weaponType; }
	void setWeaponType(Weapon type) { m_weaponType = type; }

	char* getEqWeapon() { return m_equippedWeapon; }

	int getStars() { return m_stars; }

};