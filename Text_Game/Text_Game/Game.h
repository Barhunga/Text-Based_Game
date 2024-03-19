#pragma once
#include "Player.h"
#include "Room.h"
class Game
{
public:
	Game();
	~Game();
public:
	void Run();
	void Intro();
	void Ending();
	void Print_Map();
	void Move();
public:
	Room room; 
	Player* player;
};

