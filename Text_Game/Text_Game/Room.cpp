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
	room_map[map_height - 3][map_length] = 's';
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

	// Populate map items, spells and win condition
	room_map[5][2] = 'l';
	room_map[1][4] = 'b';
	room_map[2][10] = 'k';
	room_map[6][9] = 'f';
	room_map[7][14] = 'p';
}

Room::~Room()
{
	delete lamp;
	lamp = nullptr;
	delete book;
	book = nullptr;
	delete key;
	key = nullptr;
	delete spell_01;
	spell_01 = nullptr;	
	delete spell_02;
	spell_02 = nullptr;
}

const void Room::Description(int x, int y)
{
	if (room_map[x][y] == 's') {
		cout << "\nIt seems dark in here...\n";
		room_map[x][y] = '-';
	}
	else if (room_map[x][y] == 'l') {
		lamp = new Lamp;
		room_map[x][y] = '-'; 
		lamp->Description();
	}
	else if (room_map[x][y] == 'b') {
		book = new Book;
		room_map[x][y] = '-';
		book->Description();
	}
	else if (room_map[x][y] == 'k') {
		key = new Key;
		room_map[x][y] = '-';
		key->Description();
	}	
	else if (room_map[x][y] == 'f') {
		spell_01 = new Spell('f');
		room_map[x][y] = '-';
		spell_01->Description();
	}	
	else if (room_map[x][y] == 'p') {
		spell_02 = new Spell('p');
		room_map[x][y] = '-';
		spell_02->Description();
	}
}

