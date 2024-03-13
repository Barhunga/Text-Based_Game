#include "Player.h"
// controls player things

Player::Player()
{
	x = 4;
	y = 4;
}

Player::~Player()
{
}

void Player::Move()
{ 
	cout << "Which direction would you like to move?\n"; 
	String input;  
	String* input_02 = new String();  
	input.ReadFromConsole();   
	if (input.ToLower().EqualTo("up") == true) {  
		x--;  
	} // else if 
}
