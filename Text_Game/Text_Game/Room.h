#pragma once
#include "String.h"
#include "Item.h"
#include "Lamp.h"
#include "Book.h"
#include "Key.h"
#include "Spell.h"

class Room
{
public:
	Room();
	~Room();
public:
	const void Description(int x, int y);
public:
	Lamp* lamp;
	Item* book;
	Key* key;
	Spell* spell_01;
	Spell* spell_02;
	int map_height;
	int map_length;
	int full_length;
	char room_map[9][18];
};

