#include "Player.h"

Player::Player()
{
	x = 7;
	y = 6;
}

Player::~Player()
{
}

bool Player::Find_Spell(String spell)
{
	//int L = 0;
	//int R = spells.size() - 1;
	//while (L <= R) {
	//	int M = (L + R) / 2;
	//	if (A[M] == K) {
	//		cout << "\nSpell found!\n";
	//		return true;
	//	}
	//	if (A[M] < K) L = M + 1;
	//	else if (A[M] > K) R = M – 1;
	//	}
	//cout << "\nSpell not found.\n";
	//return false;
	for (size_t i = 0; i < spells.size(); i++) {
		if (spell == spells[i].ToLower()) { 
			cout << "\nSpell found!\n" << endl;
			return true;
		}
	}
	cout << "\nSpell not found.\n" << endl;
	return false;
}


