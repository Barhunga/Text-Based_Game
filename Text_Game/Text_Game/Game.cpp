#include "Game.h"

Game::Game()
{
	player = new Player;
}

Game::~Game()
{
	delete player;
	player = nullptr;
}

void Game::Run()
{
	Intro();
	while (room.room_map[player->x][player->y] != 'w'){ // current wincon
		system("cls"); 
		Print_Map();
		room.Description(player->x, player->y); 
		Move(); 
	}
	Ending();
}

void Game::Intro()
{
	system("cls");
	cout << R"( 
	Good morning! Well, actually maybe not so much today...
	 You seem to have washed ashore on an island you don't
	    recognise. Slowly, you rise to your feet as you 
	          hear an old man rambling up ahead.
	)" << endl;
	Move();
	cout << R"( 
	       The old man comes running right up to you!
	You don't understand a single word of what he says, but
	 he hands you what seems to be a map of the island and
	                  walks off. Score!
	)" << endl;
	system("pause");
}

void Game::Ending()
{
	system("cls");
	cout << "\nYou win!\n";
}

void Game::Print_Map()
{
	int l = room.map_length;
	if (room.lamp) {
		if (room.lamp->turned_on) l = room.full_length;
	}
	cout << " ";
	for (int x = 1; x < room.map_height; x++) {
		for (int y = 0; y < l; y++) { 
			if (x == player->x && y == player->y) {
				cout << " O";
			}
			else if (room.room_map[x][y] != '-' && room.room_map[x][y] != ' ') cout << " ?";
			else cout << " " << room.room_map[x][y];
		}
		cout << endl << " ";
	}	
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~";
	if (room.lamp) {
		if (room.lamp->turned_on) cout << "~~~~~~~~";
	} 
	cout << endl;
}

void Game::Move()
{
	cout << "\nWhich direction would you like to move? (Up/Down/Left/Right)\n";
	if (room.lamp) cout << "Use lamp: L\n";
	if (room.book) cout << "Read book: B\n";
	if (room.key) cout << "Keys: " << room.key->count << endl;
	String* input = new String();
	input->ReadFromConsole();
	input->ToLower();
	if (input->EqualTo("up") == true) {
		if (room.room_map[player->x - 1][player->y] && room.room_map[player->x - 1][player->y] != ' ') player->x--;
		else {
			cout << "\nThere's something blocking the way, might need to try a different way\n";
			Move();
		}
	}
	else if (input->EqualTo("down") == true) {
		if (room.room_map[player->x + 1][player->y] && room.room_map[player->x + 1][player->y] != ' ') player->x++;
		else if (player->y >= room.map_length && player->x != room.map_height - 1) {
			cout << "\nThere's something blocking the way, might need to try a different way\n";
			Move(); 
		}
		else {
			cout << "\nThat way goes right into the ocean! Now is not the time for a swim\n";
			Move();
		}
	}
	else if (input->EqualTo("left") == true) {
		if (room.room_map[player->x][player->y - 1] && room.room_map[player->x][player->y - 1] != ' ') player->y--;
		else {
			cout << "\nThere's something blocking the way, might need to try a different way\n";
			Move();
		}
	}
	else if (input->EqualTo("right") == true) {
		if (room.room_map[player->x][player->y + 1] && room.room_map[player->x][player->y + 1] != ' ' && room.room_map[player->x][player->y + 1] != 'p') player->y++;
		else if (room.room_map[player->x][player->y + 1] == 'p' && room.key) {
			cout << "\nYou found a secret panel in the wall! What's going on here???\n";
			room.key->Use();
			player->y++;
		}
		else {
			cout << "\nThere's something blocking the way, might need to try a different way\n";
			Move();
		}
	}
	else if (input->EqualTo("l") && room.lamp != nullptr) {
		if (player->y < room.map_length) {
			cout << "\nYou can't use that here\n";
			Move();
		}
		else room.lamp->Use();
	}
	else if (input->EqualTo("b") && room.book != nullptr) {
		room.book->Use();
		}
	else {
		cout << "\nNot a valid input.\n";
		Move();
	}
}


