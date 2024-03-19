#include "Room.h"
// controls room

Room::Room()
{
	// Create game map
	map_height = 8;
	map_length = 13;
	full_length = 17;
	for (int x = 1; x < map_height; x++) { 
		for (int y = 0; y < map_length; y++) { 
			room_map[x][y] = '-'; 
		}
		for (int y = map_length; y < full_length; y++) {
			room_map[x][y] = ' ';
		}
	}

	// Create secret path
	room_map[map_height - 3][map_length] = 'p';
	room_map[map_height - 3][map_length + 1] = '-';
	room_map[map_height - 4][map_length + 1] = '-';
	room_map[map_height - 5][map_length + 1] = '-';
	room_map[map_height - 5][map_length + 2] = '-';
	room_map[map_height - 5][map_length + 3] = '-';
	room_map[map_height - 4][map_length + 3] = '-';
	room_map[map_height - 3][map_length + 3] = '-';
	room_map[map_height - 2][map_length + 3] = '-';
	room_map[map_height - 2][map_length + 2] = '-';
	room_map[map_height - 1][map_length + 2] = '-';

	// Populate map items and win condition
	room_map[5][2] = 'l';
	room_map[7][14] = 'w';
}

Room::~Room()
{
	delete lamp;
	lamp = nullptr;
}

const void Room::Description(int x, int y)
{
	if (room_map[x][y] == 'p') {
		cout << "\nYou found a secret panel in the wall! What's going on here???\n";
		room_map[x][y] = '-';
	}
	else if (room_map[x][y] == 'l') {
		lamp = new Lamp;
		room_map[x][y] = '-'; 
		lamp->Description();
	}
}

