#pragma once
#include<iostream>
#include<vector>
#include"GameCharacter.h"
using namespace std;
class Room
{
public:
	Room();
	Room(bool, int, int, Object*,int,int);
	void clearObject();

	void setUpRoom(Room* );
	void setDownROom(Room* );
	void setLeftRoom(Room*);
	void setRightRoom(Room* );
	void setIsExit(bool);
	void setHungerDrop(int hd);
	void setThirstDrop(int td);
	void addObjects(Object*);

	Room* getUpRoom() const;
	Room* getDownRoom()const;
	Room* getRightRoom()const;
	Room* getLeftRoom()const;
	bool getIsExit()const;
	int getIndex() const;
	int getHungerDrop()const;
	int getThirstDrop() const;
	vector<Object*> getObjects()const;
	int getRoomType();
private:
	
	Room* upRoom=NULL;
	Room* downRoom=NULL;
	Room* leftRoom=NULL;
	Room* rightRoom=NULL;
	bool isExit;
	int index;
	int type;
	int hungerDrop=0;
	int thirstDrop=0;		
	vector<Object*>objects;
	
};