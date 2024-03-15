#pragma once
#include "String.h"
#include "Item.h"

class Room
{
public:
	Room();
	Room(String descript, Item* item);
	~Room();
public:
	const void Description(int x, int y);
public:
	Item* item;
	String description;
	int map_height;
	int map_length;
	char room_map[7][13];
};

