#pragma once
#include "Item.h"

class Key : public Item
{
public:
	Key();
public:
	const void Description() override; 
	void Use() override; 
public:
	int count;
};

