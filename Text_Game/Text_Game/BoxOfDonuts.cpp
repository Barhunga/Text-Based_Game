#include "BoxOfDonuts.h"
// child class of item
BoxOfDonuts::BoxOfDonuts()
{
	count = 6;
}

const void BoxOfDonuts::Description()
{
	return void();
}

void BoxOfDonuts::Use()
{
	count -= 1;
}
