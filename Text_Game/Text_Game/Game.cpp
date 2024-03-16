#include "Game.h"
// runs the game

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
	while (player->x != room.map_height - 2 || player->y != room.map_length){
		system("cls"); 
		Print_Map(); 
		room.Description(player->x, player->y); 
		player->Move(); 
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
	player->Move();
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
	cout << "\nYou win!\n";
}

void Game::Print_Map()
{
	for (int x = 0; x < room.map_height; x++) {
		for (int y = 0; y < room.map_length; y++) {
			if (x == player->x && y == player->y) {
				cout << " O";
			}
			else cout << " " << room.room_map[x][y];
		}
		cout << endl;
	}
	cout << endl;
}


