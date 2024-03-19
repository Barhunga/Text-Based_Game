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
	room_map[1][4] = 'b';
	room_map[2][10] = 'k';
	room_map[7][14] = 'w';
}

Room::~Room()
{
	delete lamp;
	lamp = nullptr;
	delete key;
	key = nullptr;
}

const void Room::Description(int x, int y)
{
	if (room_map[x][y] == 'p') {
		room_map[x][y] = '-';
	}
	else if (room_map[x][y] == 'l') {
		lamp = new Lamp;
		room_map[x][y] = '-'; 
		lamp->Description();
	}
	else if (room_map[x][y] == 'b') {
		item = new Book;
		room_map[x][y] = '-';
		item->Description();
	}
	else if (room_map[x][y] == 'k') {
		key = new Key;
		room_map[x][y] = '-';
		key->Description();
	}
}

