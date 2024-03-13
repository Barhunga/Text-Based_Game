#include "Room.h"
// controls room

Room::Room()
{

}

Room::Room(String descript, Item* item)
{

}

Room::~Room()
{
	delete item;
	item = nullptr;
}

