#include "Player.h"

Player::Player()
{
	x = 7;
	y = 6;
}

Player::~Player()
{
}

void Player::Add_Spell(String spell)
{
	spells.push_back(spell.ToLower());
	// Sort vector (for use with binary search)
	bool swapped = false;
	size_t i = 0; 
	do {
		swapped = false;
		for (size_t j = 0; j < (spells.size() - 1 - i); j++) { 
			if (spells[j] > spells[j + 1]) { 
				String temp = spells[j]; 
				spells[j] = spells[j + 1]; 
				spells[j + 1] = temp; 
				swapped = true; 
			}
		}
		i++;
	} while (swapped);
}

bool Player::Find_Spell(String spell)
{
	// Binary search
	size_t L = 0;
	size_t R = spells.size() - 1;
	while (L <= R) {
		size_t M = (L + R) / 2;
		if (spells[M].ToLower() == spell.ToLower()) {
			cout << "\nSpell found!\n" << endl;
			return true;
		}
		if (spells[M].ToLower() < spell.ToLower()) L = M + 1;
		else if (spells[M].ToLower() > spell.ToLower()) R = M - 1;
		}
	cout << "\nSpell not found.\n" << endl;
	return false;
	// Regular search
	//for (size_t i = 0; i < spells.size(); i++) {
	//	if (spell == spells[i].ToLower()) { 
	//		cout << "\nSpell found!\n" << endl;
	//		return true;
	//	}
	//}
	//cout << "\nSpell not found.\n" << endl;
	//return false;
}


