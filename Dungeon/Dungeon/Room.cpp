#include"Room.h"
Room::Room() {}
Room::Room(bool isExit, int index, int type, Object* obj,int hd,int td)
{
	this->isExit = isExit;
	this->index = index;
	this->type = type;
	this->hungerDrop = hd;
	this->thirstDrop = td;
	if(obj!=NULL)
		addObjects(obj);
}
void Room::clearObject()
{
	objects.clear();
}
void Room::setUpRoom(Room* room)
{
	upRoom = room;
}
void Room::setDownROom(Room* room)
{
	downRoom = room;
}
void Room::setLeftRoom(Room*room)
{
	leftRoom = room;
}
void Room::setRightRoom(Room* room)
{
	rightRoom = room;
}
void Room:: setIsExit(bool b)
{
	isExit = b;
}
void Room::setHungerDrop(int hd)
{
	hungerDrop = hd;
}
void Room::setThirstDrop(int td)
{
	thirstDrop = td;
}
void Room::addObjects(Object*obj)
{
	objects.push_back(obj);
}

Room* Room::getUpRoom()const
{
	return upRoom;
}
Room* Room::getDownRoom()const
{
	return downRoom;
}
Room* Room::getLeftRoom()const
{
	return leftRoom;
}
Room* Room::getRightRoom()const
{
	return rightRoom;
}
bool Room::getIsExit() const
{
	return isExit;
}
int Room::getIndex()const
{
	return index;
}
int Room:: getHungerDrop()const
{
	return hungerDrop;
}
int Room::getThirstDrop()const
{
	return thirstDrop;
}
vector<Object*> Room:: getObjects()const
{
	return objects;
}
int Room::getRoomType()
{
	return type;
}