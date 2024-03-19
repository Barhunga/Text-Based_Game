#pragma once
#include "Item.h"

class Book : public Item
{
public:
	Book();
public:
	const void Description() override;
	void Use() override;
};

