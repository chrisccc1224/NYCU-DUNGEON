#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Item.h"
#include"GameCharacter.h"
using namespace std;
class NPC :public GameCharacter
{
public:
	NPC() ;
	NPC(string, string, vector<Item>) ;
	void listCommodity();
	bool buyItem(Item);
	bool triggerEvent(Object*);
	void setScript(string);
	void addCommodity(Item);
	string getScript() const;
	vector<Item>getCommmodity()const;
	void showStatus();
private:
	string script;
	vector<Item>commodity;
	
};