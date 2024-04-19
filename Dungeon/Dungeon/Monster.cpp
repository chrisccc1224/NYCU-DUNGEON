#include"Monster.h"

Monster::Monster() {}
Monster::Monster(string name, int maxHp, int atk, int def,int coin)
{
	this->setName(name);
	this->setMaxHp(maxHp);
	this->setCurrentHp(maxHp);
	this->setAtk(atk);
	this->setDef(def);
	this->setTag("Monster");
	this->coin = coin;
	
}
int Monster::getCoin()
{
	return coin;
}
void Monster::showStatus()
{
	cout << getName() << ":\n"
		<< "Hp: " << getCurrentHp() << '\n'
		<< "Atk:" << getAtk() << '\n'
		<< "Def: " << getDef() << '\n';
}
void Monster::addPoison(Poison p)
{
	poisons.push_back(p);
}
vector<Poison> Monster::getPoisons()
{
	return poisons;
}
bool Monster::triggerEvent(Object* obj)
{
	Player* p = dynamic_cast<Player*>(obj);

	while (p->getCurrentHp() > 0)
	{
		p->runPoison();
		cout << "monster HP:" << getCurrentHp() << '\n';
		cout << "You want to (1)attack or (2)retreat:";
		
		int action;
		cin >> action;
		if (action == 1)
		{
			cout << "You attack " << getName() << '\n';
			if (p->getOccu() == 1) cout << getName() << " left " << takeDamage(p->getAtk()+p->getMaxHp()-p->getCurrentHp()) << " Hp\n";
			else cout << getName() << " left " << takeDamage(p->getAtk()) << " Hp\n";
			if (p->getOccu() == 2)
			{
				cout << "+" << (p->getAtk() - getDef()) / 10 << "Hp!!\n";
				p->setCurrentHp(p->getCurrentHp() + (p->getAtk() - getDef()) / 10);
			}
			
		

			if (getCurrentHp() <= 0) return 1;
			cout << getName() << " attack you\n";
		
			cout << "you left " << p->takeDamage(getAtk()) << " Hp\n";

			if (getName() == "Desert Guardian")
			{
				int r = rand() % 10;
				if (r == 0) p->addPoison(getPoisons()[0]);
			}
			else if (getName() == "Tiger" || getName() == "Bear")
			{
				int r = randomNum(10, 5, 85);
				if (r == 0) p->addPoison(getPoisons()[0]);
				else if (r == 1)p->addPoison(getPoisons()[1]);
			}
		}
		else if (action == 2) return 0;
	}

}