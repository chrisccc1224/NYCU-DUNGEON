#pragma once
#include<iostream>
#include<vector>

#include"Item.h"

class Poison:public Item
{
public:
	Poison();
	Poison(string,int, int, int, int);
	void setTime(int time);
	int  getTime() const;
	void showStatus();
	
private:
	int time;
};