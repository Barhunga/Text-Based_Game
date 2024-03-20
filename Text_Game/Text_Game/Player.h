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
	bool Find_Spell(String spell);
public:
	vector<String> spells;
	int x, y;
};

// wisdom - compass