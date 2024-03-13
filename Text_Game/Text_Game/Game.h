#pragma once
#include "Player.h"
#include "Room.h"
class Game
{// runs the game
public:
	Game();
	~Game();
public:
	void Run();
	void Print_Map();
	void Move();
public:
	Room rooms; // [][] 
	Player* player;
	char map[5][9];
};

