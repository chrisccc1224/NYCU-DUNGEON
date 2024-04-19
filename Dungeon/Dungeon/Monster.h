#pragma once
#include"GameCharacter.h"
#include"Player.h"
#include"Random.h"
class Monster:public GameCharacter
{
public:
	Monster();
	Monster(string, int, int, int,int);
	bool triggerEvent(Object*);
	int getCoin();
	void showStatus();
	void addPoison(Poison);
	vector<Poison>getPoisons();
private:
	int coin;
	vector<Poison> poisons;
};