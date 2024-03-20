#include "Spell.h"

Spell::Spell(char id)
{
	casted = false;
	spell_id = id;
	if (spell_id == 'p') spell_name = String("Portalise"); 
	//else if (spell_id == 'c') spell_name = String("");	
}

void Spell::Description()
{
	if (spell_id == 'p') {
		cout << R"(
	  You found a secret spring! You hear a voice speak
	         to you from inside as you walk in.

	      "You have done well to find this place"

	"I shall bestow my power upon you. Should you attempt
	to use it, you will find a portal standing before you.
	     Only those with courage shall find out what 
	             awaits on the other side..."
	)" << endl;
	}
	//else if (spell_id == 'c')
	//	cout << "\nYou found a nice spring! " << spell_name.CStr() << " \n";	
}

void Spell::Cast()
{
	cout << "\nYou channel the power of the voice you heard earlier.\n\n";
	casted = true;
	system("pause");
}
