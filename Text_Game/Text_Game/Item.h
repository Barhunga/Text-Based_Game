#pragma once
#include <iostream>
using namespace std;

class Item
{
public:
	virtual const void Description() = 0; 	
	virtual void Use() = 0;					
};
