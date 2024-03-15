#include "Room.h"
// controls room

Room::Room()
{
	map_height = 7;
	map_length = 13;
	for (int x = 0; x < map_height; x++) { 
		for (int y = 0; y < map_length; y++) { 
			room_map[x][y] = '-'; 
		}
	}
}

Room::Room(String description, Item* item)
{

}

Room::~Room()
{
	delete item;
	item = nullptr;
}

const void Room::Description(int x, int y)
{
	// if room_map[x][y] (or if x and y == coordinates of) has an item or something notable, print the room/item description
}

