#pragma once
#include <iostream>
#include <vector>
#include "String.h"
#include "Spell.h"
using namespace std;

class Player
{
public:
	Player();
	~Player();
public:
	void Add_Spell(String spell);
	bool Find_Spell(String spell);
public:
	vector<String> spells;
	int x, y;
};
