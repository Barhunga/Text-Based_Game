#pragma once
#include <iostream>
#include <vector>
#include "String.h"
using namespace std;

class Player
{
public:
	Player();
	~Player();
public:
	void Move();
	bool Find_Spell(String spell);
public:
	vector<String> spells;
	int x, y;
};

