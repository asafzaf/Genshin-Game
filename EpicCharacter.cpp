#include "EpicCharacter.h"

EpicCharacter::EpicCharacter(char* name, const char* location, Element E_type, Weapon W_type, char* eq_wea, int star) : Character(name, location, E_type, W_type, eq_wea, star) {};

int EpicCharacter::Attack() { // No need to explain.
	printWeaponsActive();
	return 15;
}