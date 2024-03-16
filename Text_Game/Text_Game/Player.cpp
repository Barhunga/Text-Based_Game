#include "Player.h"
// controls player things

Player::Player()
{
	x = 6;
	y = 6;
}

Player::~Player()
{
}

void Player::Move()
{
	cout << "Which direction would you like to move?\n";
	String* input = new String();
	input->ReadFromConsole();
	if (input->ToLower().EqualTo("up") == true) {
		if (x != 0) x--;
		else {
			cout << "\nThere's something blocking the way, might need to try a different way\n\n";
			Move();
		}
	}
	else if (input->ToLower().EqualTo("down") == true) {
		if (x != 6) x++;
		else {
			cout << "\nThat way goes right into the ocean! Now is not the time for a swim\n\n";
			Move();
		}
	}
	else if (input->ToLower().EqualTo("left") == true) {
		if (y != 0) y--;
		else {
			cout << "\nThere's something blocking the way, might need to try a different way\n\n";
			Move();
		}
	}
	else if (input->ToLower().EqualTo("right") == true) {
		if (y < 12) y++;
		else if (y == 12 && x == 4/*change to 4*/) { // secret door
			cout << "\nYou found a secret panel in the wall! What's going on here???\n\n";
			y++;
			system("pause");
		}
		else if (y == 12 && x == 5) y++; // dev route - delete
		else if (y > 12 && y < 15 && x == 3) y++; // secret path
		else{
			cout << "\nThere's something blocking the way, might need to try a different way\n\n";
			Move();
		}
	}
	else {
		cout << "\nNot a valid input.\n\n";
		Move();
	}
}

