#pragma once

#include<iostream>
#include<string>
#include "Object.h"

using namespace std;

class Item : public Object
{
public:
	Item();
	Item(string, string ,int, int, int,int,int,int);
	void setHp(int );
	void setAtk(int);
	void setDef(int );
	void setHunger(int);
	void setThirst(int);
	void setRemovePoison(bool);
	int getHp()const;
	int getAtk()const;
	int getDef()const;
	int getHunger()const;
	int getThirst()const;
	bool getRemovePoison()const;
	bool triggerEvent(Object*);
	void setType(string);
	string getType();
	int getPrice() const;
	void setPrice(int price);
	void showStatus();
private:
	int hp;
	int atk;
	int def;
	int hunger;
	int thirst;
	int price;
	string type;
	bool removePoison = 0;	
	
};
#include"Poison.h"