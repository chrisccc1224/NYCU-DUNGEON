#include<iostream>
#include<string>
#include"GameCharacter.h"
using namespace std;

GameCharacter::GameCharacter(){}
GameCharacter::GameCharacter(string name, string tag, int maxHp, int atk, int def)
{
	this->setName(name);
	setTag(tag);
	this->maxHp = maxHp;
	this->atk = atk;
	this->def = def;
}
bool GameCharacter::checkisDead()
{
	if (currentHp <= 0) return 1;
	return 0;
}
int GameCharacter::takeDamage(int dmg)
{
	if (dmg < def) {}
	else currentHp =currentHp-dmg+def>0?currentHp-dmg+def:0;
	return currentHp;
}
void GameCharacter::setMaxHp(int maxHp)
{
	this->maxHp = maxHp;
}
void GameCharacter::setCurrentHp(int currentHp)
{
	if (currentHp < maxHp)this->currentHp = currentHp;
	else this->currentHp = maxHp;
}
void GameCharacter::setAtk(int atk)
{
	this->atk = atk;
}
void GameCharacter::setDef(int def )
{
	this->def = def;
}
int GameCharacter:: getMaxHp()const
{
	return maxHp;
}
int GameCharacter::getCurrentHp()const
{
	return currentHp;
}
int GameCharacter::getAtk()const
{
	return atk;
}
int GameCharacter::getDef()const
{
	return def;
}