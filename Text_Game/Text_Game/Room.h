#pragma once
#include "String.h"
#include "Item.h"
#include "Lamp.h"

class Room
{
public:
	Room();
	~Room();
public:
	const void Description(int x, int y);
public:
	Lamp* lamp;
	String description;
	int map_height;
	int map_length;
	int full_length;
	char room_map[9][18];
};

