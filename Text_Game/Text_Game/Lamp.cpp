#include "Lamp.h"
Lamp::Lamp()
{
	turned_on = false;
}

const void Lamp::Description()
{
	cout << "\nYou found a lamp! Use it to light up dark places\n";
}

void Lamp::Use()
{
	if (!turned_on) {
		turned_on = true;
		cout << "\nYou turned on your lamp\n";
	}
	else {
		turned_on = false;
		cout << "\nYou turned off your lamp\n";
	}
	cout << endl; 
	system("pause");
}