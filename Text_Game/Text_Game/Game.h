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
	void Intro();
	void Ending();
	void Print_Map();
public:
	Room room; // [][] 
	Player* player;
};

