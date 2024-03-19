#include "BoxOfDonuts.h"

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
