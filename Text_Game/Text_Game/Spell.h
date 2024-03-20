#pragma once
#include <iostream>
#include "String.h"
using namespace std;
class Spell
{
public:
	Spell(char id);
public:
	void Description();
	void Cast();
public:
	bool casted;
private:
	char spell_id;
};

