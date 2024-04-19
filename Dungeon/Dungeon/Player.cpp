#include"Player.h"

Player::Player() {}
Player::Player(string name, int maxHp, int atk, int def, int hunger,int thirst,int coin, int occu)
{
	this->setName(name);
	this->setMaxHp(maxHp);
	this->setCurrentHp(maxHp);
	this->setAtk(atk);
	this->setDef(def);
	this->hunger = hunger;
	this->thirst = thirst;
	this->coin = coin;
	this->occupation = occu;
}
void Player::addItem(Item it)
{
	increaseStates(it.getHp(), it.getHp(), it.getAtk(), it.getDef(), 0, 0);
	inventory.push_back(it);
}
void Player::increaseStates(int maxHp, int hp, int atk, int def, int hunger, int thirst)
{
	this->setMaxHp(getMaxHp() + maxHp);
	this->setCurrentHp(getCurrentHp()+hp<=this->getMaxHp() ? getCurrentHp() + hp : getMaxHp());
	this->setAtk(getAtk() + atk);
	this->setDef(getDef() + def);
	this->hunger += hunger;
	this->thirst += thirst;
	if (hunger > 15)hunger = 15;
	if (thirst > 15)thirst = 15;
}
void Player::changeRoom(Room*r)
{
	if (r != NULL)
	{
		prevRoom = currentRoom;
		currentRoom = r;
	}
	else
	{
		cout << "Unavailable Direction!!!\n";
	}

}
void Player:: addPoison(Poison p)
{
	poisons.push_back(p);
}
bool Player::triggerEvent(Object*)
{
	return 0;
}
vector<Item> Player::getInventory()
{
	return inventory;
}
Room* Player::getCurrentRoom() const
{
	return currentRoom;
}
Room* Player::getPrevRoom()const
{
	return prevRoom;
}
void Player::setPrevRoom(Room* r)
{
	prevRoom = r;
}
void Player::setCurrentRoom(Room*r)
{
	currentRoom = r;
}
void Player::showStatus()
{
	cout << "Status:\n"
		<< getName() << '\n'
		<< "HP: " << getCurrentHp() << '/' << getMaxHp() << '\n'
		<< "Atk: " << getAtk() << '\n'
		<< "Def: " << getDef() << '\n'
		<< "Hunger: " << hunger << '\n'
		<< "Thirst: " << thirst << '\n'
		<< "Coin: " << coin << '\n'
		<< "Poison:\n";
	for (int i = 0; i < poisons.size(); i++)
	{
		cout << i + 1 << ".\n";
		poisons[i].showStatus();
	}
}
void Player:: showInventory()const
{
	for (int i = 0; i < inventory.size(); i++)
	{
		cout << i+1 << ". " << inventory[i].getName()<<'\n';
	}
}
void Player::addFood(Item i)
{
	foods.push_back(i);
}
vector<Item>Player:: getFoods()
{
	return foods;
}
void Player::showFood()
{
	for (int i = 0; i < foods.size(); i++)
	{
		cout << i + 1 << ". " << foods[i].getName() << '\n';
	}
}
void Player::removeFood(int i)
{
	foods.erase(foods.begin()+i);
}
void Player::setCoin(int coin)
{
	this->coin = coin;
}
int Player::getCoin() const
{
	return coin;
}
void Player::runPoison()
{
	for (int i = 0; i < poisons.size(); i++)
	{
		if (poisons[i].getTime() > 0)
		{
			cout << "You are Poisoned!!\n";
			cout << "-" << poisons[i].getHp() << "Hp\n";
			setCurrentHp(getCurrentHp() - poisons[i].getHp());
			poisons[i].setTime(poisons[i].getTime() - 1);
		}
	}
	for (int i = 0; i < poisons.size(); i++)
	{
		if (poisons[i].getTime() <= 0)
		{
			poisons.erase(poisons.begin() + i);
			i--;
		}
	}
}
int Player::getHunger()const
{
	return hunger;
}
int Player::getThirst()const
{
	return thirst;
}
void Player:: setHunger(int h)
{
	if (h < 0) hunger = 0;
	else if (h > 15)hunger = 15;
	else hunger = h;
	
}
void Player::setThirst(int t)
{
	if (t < 0)thirst = 0;
	else if (t > 15)thirst = 15;
	else 	thirst = t;

}
void Player::removePoison()
{
	poisons.clear();
}
int Player::getOccu()const
{
	return  occupation;
}