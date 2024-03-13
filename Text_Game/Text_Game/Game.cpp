#include "Game.h"
// runs the game

Game::Game()
{
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 9; y++) {
			map[x][y] = '-';
		}
	}
	player = new Player;
}

Game::~Game()
{
	delete player;
	player = nullptr;
}

void Game::Run()
{
	while (player->x != 0 && player->y != 8){
		system("cls"); 
		Print_Map(); 
		Move(); 
	}
}

void Game::Print_Map()
{
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 9; y++) {
			if (x == player->x && y == player->y) {
				cout << " P";
			}
			else cout << " " << map[x][y];
		}
		cout << endl;
	}
	cout << endl;
}

void Game::Move()
{
	cout << "Which direction would you like to move?\n";
	String input;
	String* input_02 = new String();
	input.ReadFromConsole();
	if (input.ToLower().EqualTo("up") == true) {
		player->x--;
	} 
	else if (input.ToLower().EqualTo("down") == true) {
		player->x++;
	}
	else if (input.ToLower().EqualTo("left") == true) {
		player->y--;
	}
	else if (input.ToLower().EqualTo("right") == true) {
		player->y++;
	}
}

