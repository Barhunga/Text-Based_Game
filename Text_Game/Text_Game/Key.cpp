#include "Key.h"

Key::Key()
{
	count = 1;
}

const void Key::Description()
{
	cout << "\nYou found a key! Where could this go?\n";
}

void Key::Use()
{
	count -= 1;
	cout << "\nYou place your key into a small hole in the wall\n" << endl;
	system("pause");
}
