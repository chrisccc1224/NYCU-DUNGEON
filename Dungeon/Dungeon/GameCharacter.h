#pragma once
#include<iostream>
#include<string>
#include"Object.h"
using namespace std;

class GameCharacter : public Object
{
public:
	GameCharacter();
	GameCharacter(string, string, int, int, int);
	bool checkisDead();
	int takeDamage(int);
	
	void setMaxHp(int);
	void setCurrentHp(int);
	void setAtk(int);
	void setDef(int);
	int getMaxHp()const;
	int getCurrentHp()const;
	int getAtk()const;
	int getDef()const;
private:
	int maxHp;
	int currentHp;
	int atk;
	int def;

};