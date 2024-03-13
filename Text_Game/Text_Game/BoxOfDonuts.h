#pragma once
#include "Item.h"

class BoxOfDonuts : public Item
{
public:
	BoxOfDonuts();
public:
	virtual const void Description();
	virtual void Use();
public:
	int count;
};

