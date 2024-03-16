#include "Room.h"
// controls room

Room::Room()
{
	// Create game map
	map_height = 7;
	map_length = 13;
	for (int x = 0; x < map_height; x++) { 
		for (int y = 0; y < map_length; y++) { 
			room_map[x][y] = '-'; 
		}
	}
}

Room::Room(String descript, Item* item)
{
	//item->Description(/*descript?*/);

}

Room::~Room()
{
	delete item;
	item = nullptr;
}

const void Room::Description(int x, int y)
{
	// make item* item (what about inherited item classes? - start without?) somewhere to make and place items on the map
	// can make seperate functions or use constructor? for making/placing items and reading the description of the room
	// if room_map[x][y] (or if x and y == coordinates of) has an item or something notable, print the room/item description
}

