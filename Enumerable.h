#pragma once

// This project made by Asaf Zafrir (205929029)

//---        Enumerable.h          ---//

const char* weaponEnumToText(int index);
const char* elementEnumToText(int index);


enum Element {
	Uninitialized,
	Ameno,
	Pyro,
	Cyro,
	Hydro,
	Electro,
	Geo,
	Dendro
};

enum Weapon {
	unarmed,
	Sword,
	Polearm,
	Catalyst,
	Claymore,
	Bow
};

const char* elementEnumToText(int index) {
	switch (index)
	{
	case 1:
		return "Ameno";
	case 2:
		return "Pyro";
	case 3:
		return "Cyro";
	case 4:
		return "Hydro";
	case 5:
		return "Electro";
	case 6:
		return "Geo";
	case 7:
		return "Dendro";
	default:
		return "Err";
		break;
	}
}

const char* weaponEnumToText(int index) {

}