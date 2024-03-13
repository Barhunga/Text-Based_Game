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
	map[player->x][player->y] = 'O';
}

Game::~Game()
{
	delete player;
	player = nullptr;
}

void Game::Run()
{
	system("cls");
	Print_Map();
	Move();
	system("cls");
	Print_Map();
}

void Game::Print_Map()
{
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 9; y++) {
			cout << map[x][y] << " ";
		}
		cout << endl;
	}
}

void Game::Move()
{
	cout << "Which direction would you like to move?\n";
	String input;
	String* input_02 = new String();
	input.ReadFromConsole();
	map[player->x][player->y] = '-';
	if (input.ToLower().EqualTo("up") == true) {
		player->x--;
		map[player->x][player->y] = 'O';
	} // else if 
}

