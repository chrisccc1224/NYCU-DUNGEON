#pragma once
#include<iostream>
#include "Room.h"
#include"Item.h"
#include"GameCharacter.h"
#include"Poison.h"
#include"Buff.h"
using namespace std;
class Player:public GameCharacter
{
public:
	Player() ;
	Player(string, int hp, int atk, int def,int hunger,int thirst,int coin,int occu);
	void addItem(Item);
	void increaseStates(int ,int, int, int,int,int);
	void changeRoom(Room*);
	bool triggerEvent(Object*);
	void addPoison(Poison);
	
	vector<Item> getInventory();
	Room* getCurrentRoom()const;
	Room* getPrevRoom() const;
	void setPrevRoom(Room*);
	void setCurrentRoom(Room*);
	
	void showStatus();
	void showInventory() const;
	void addFood(Item);
	void showFood();
	vector<Item> getFoods();

	void removePoison();
	void removeFood(int);
	void setCoin(int);
	int getCoin() const;
	void runPoison() ;
	int getHunger() const;
	int getThirst()const;
	void setHunger(int h);
	void setThirst(int t);
	int getOccu()const;
private:
	Room* currentRoom;
	Room* prevRoom;
	vector<Item> inventory;
	vector<Item>foods;
	int hunger;
	int thirst;
	vector<Poison> poisons;
	int occupation;
	int coin;
	


};