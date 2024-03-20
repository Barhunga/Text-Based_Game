#include "Book.h"

Book::Book()
{
}

const void Book::Description()
{
	cout << "\nYou found a book lying on the ground! Might be worth a read\n";
}

void Book::Use()
{
	cout << "\nYou decide to have a quick read of the book you found.\n";
	cout << R"(
	Legend has it this island hides a secret near the sea
	which allows anyone to create a portal off the island.
	I've searched tirelessly to no avail. Alas, no other
	way has been found. My last hope hangs on the words 
	of an old rambling man. "Far east of the lamp, an 
	adventurous soul finds what he is searching for". 
	There must be something I'm missing...
	)" << endl;
	system("pause");
}
