#include"Poison.h"
Poison::Poison(){}
Poison::Poison(string name, int hp, int atk, int def,int time)
{
	setTag("Poison");
	setName(name);
	setHp(hp);
	setAtk(atk);
	setDef(def);
	this->time = time;
	setType("Poison");
}
void Poison:: setTime(int time)
{
	this->time = time;
}
int Poison::getTime() const
{
	return time;
}
void Poison::showStatus()
{
	cout << getName() << ":\n"
		<< "-Hp/round: " << getHp() << '\n'
		<< "Time left: " << time<<'\n';
}
