#include"NPC.h"
#include"Player.h"
NPC::NPC() {};
NPC::NPC(string name,string script,vector<Item>items)
{
	this->setName(name);
	this->script = script;
	this->commodity = items;
	this->setTag("NPC");

}
void NPC::listCommodity()
{
	for (int i = 0; i < commodity.size(); i++)
	{
		cout <<i+1<< " Name: " << commodity[i].getName() << " Price: " << commodity[i].getPrice() << '\n';
	}
}

void NPC:: showStatus()
{

}
bool NPC::triggerEvent(Object*obj)
{
	cout << getScript()<<'\n';
	if (getName() == "Friendly Villager")
	{
		
		for (int i = 0; i < commodity.size(); i++)
		{
			commodity[i].setPrice(0);
		}
	}
	Player* p = dynamic_cast<Player*>(obj);
	getScript();
	if (getName() == "Trader" || getName() == "Friendly Villager")
	{
		cout << "You have " << p->getCoin() << " dollars\n";
		listCommodity();
		cout << "input 0 to return :\n";
		int buy;
		cin >> buy;
		if (buy == 0) return 0;
		else if (buy > commodity.size())
		{
			cout << "Invalid Number!!";
			return 0;
		}
		else if (p->getCoin() < commodity[buy - 1].getPrice())
		{
			cout << "You're too poor!\n";
			return 0;
		}
		else 
		{
			if (p->getCoin() >= commodity[buy - 1].getPrice())
			{
				p->setCoin(p->getCoin() - commodity[buy - 1].getPrice());
				if (commodity[buy - 1].getType() == "Food")p->addFood(commodity[buy - 1]);
				else if (commodity[buy - 1].getType() == "Equip") p->addItem(commodity[buy - 1]);
			}
			cout << "You get" << commodity[buy - 1].getName() << '\n';
			return 1;
		}
	}
	else if (getName() == "Mysterious Man")
	{
		cout << "Accept the gift? (1)Yes (2)No: ";
		int action;
		cin >> action;
		if (action == 1)
		{
			Item it =commodity[0];
			cout << "You get " << it.getName() << "!!!\n";

			if (it.getType() == "equip") p->addItem(it);
			
			else if (it.getType() == "Poison")
			{
				p->addPoison(Poison("Normal poison", 15, 0, 0, 3));
			}
			else if (it.getType() == "Food")p->addFood(it);
			return 1;
		}
		else return 0;

	}
}
string NPC::getScript()const
{
	return script;
}
void NPC::addCommodity(Item it )
{
	commodity.push_back(it);
}