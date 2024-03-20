#include "Spell.h"

Spell::Spell(char id)
{
	casted = false;
	spell_id = id;
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
	else if (spell_id == 'f'){
		cout << R"(
	   You found a nice spring! You hear a voice speak
	         to you from inside as you walk in.

	           "You were wise to come here."

	"I shall bestow my power upon you. Should you attempt
	 to use it, you will find yourself suddenly aware of
	     anything of use to you here on this island."
	)" << endl; 
	}	
}

void Spell::Cast()
{
	if (!casted) {
		cout << "\nYou channel the power of the voice you heard earlier.\n\n";
		casted = true;
	}
	else {
		cout << "\nYou stop channeling the power of the voice you heard earlier.\n\n";
		casted = false;
	}
	system("pause");
}
