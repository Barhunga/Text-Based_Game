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
	const void Description();
public:
	Item* item;
	String description;
};

