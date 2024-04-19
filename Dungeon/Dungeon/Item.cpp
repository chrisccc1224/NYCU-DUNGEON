#include<iostream>
#include<string>
#include"Item.h"
#include"Player.h"
using namespace std;
Item::Item() {}
Item::Item(string name,string type, int hp, int atk, int def,int hunger,int thirst,int price)
{
	this->setName(name);
	this->type = type;
	this->hp=hp;
	this->atk = atk;
	this->def = def;
	this->hunger = hunger;
	this->thirst = thirst;
	this->price = price;
}
void Item::setHp(int hp)
{
	this->hp = hp;
}
void Item::setAtk(int atk)
{
	this->atk = atk;
}
void Item::setDef(int def)
{
	this->def = def;
}
void Item:: setHunger(int hunger)
{
	this->hunger = hunger;
}
void Item::setThirst(int thirst)
{
	this->thirst = thirst;
}
void Item::setRemovePoison(bool rp)
{
	removePoison = rp;
}
void Item::setType(string type)
{
	this->type = type;
}

int Item::getHp()const
{
	return hp;
}
int Item::getAtk()const
{
	return atk;
}
int Item :: getDef()const
{
	return def;
}
int Item::getHunger()const
{
	return hunger;
}
int Item::getThirst()const
{
	return thirst;
}
bool Item :: getRemovePoison()const
{
	return removePoison;
}

bool Item::triggerEvent(Object* obj)
{
	Player* p = dynamic_cast<Player*>(obj);
	if (type != "Food") return 0;
	else	p->increaseStates(0, hp, atk, def, hunger, thirst);
	cout << "You consume " << getName()<<"!\n";
	if (removePoison == 1)
	{
		p->removePoison();
		cout << "Poison clear!!\n";
	}
	return 0;
}
string Item::getType()
{
	return type;
}
void Item:: showStatus()
{
	cout << "Item Type: " << type << '\n'
		<< "Item Name: " << getName() << '\n'
		<< "Item +Hp" << hp << '\n'
		<< "Item +Atk: " << atk << '\n'
		<< "Item +Def: " << def << '\n'
		<< "Item +Hunger: " << hunger << '\n'
		<< "Item +Thirst: " << thirst << '\n';
	string removep = removePoison ? "yes" : "no";
	cout << "RemovePoison: " << removep << '\n';
}
int Item::getPrice() const
{
	return price;
}
void Item::setPrice(int price)
{
	this->price = price;
}