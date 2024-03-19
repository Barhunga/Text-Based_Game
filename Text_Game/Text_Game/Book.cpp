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
	cout << "\nYou decide to have a quick read of this book you found.\n";
	cout << R"(
	Legend has it the only escape from this island is via a 
	hidden portal near the sea. I've searched tirelessly, to
	no avail. Alas, no other way has been found. My last hope
	hangs on the words of an old rambling man. "East of the
	lamp, a keen eye finds what he is searching for". There
	must be something I'm missing.
	)" << endl;
	system("pause");
}
