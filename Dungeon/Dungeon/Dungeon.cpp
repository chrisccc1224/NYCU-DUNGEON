#include "Dungeon.h"

Item Lake("Lake", "Special", 0, 0, 0, 0, 0, 0);
Item Oasis("Oasis", "Special", 0, 0, 0, 0, 0, 0);

Dungeon::Dungeon(){}
void Dungeon::createPlayer()
{
	cout << "Type your name:";
	string name;
	cin >> name;
	int occu;
	cout << "Choose Your Occupation:\n"
		<< "1. Knight:atk up when hp low\n"
		<< "2. Vampire:heal when attack\n"
		<< "3  Warrior: high hp,atk,def\n";
	cin >> occu;
	while (occu < 1 || occu>3)
	{
		cout << "Invalid Number!!\n";
		cout << "Choose Your Occupation:\n"
			<< "1. Knight:atk up when hp low\n"
			<< "2. Vampire:heal when attack\n"
			<< "3  Warrior: high hp,atk,def\n";
		cin >> occu;
	}
	
	if (occu == 1) player = Player(name, 150, 20, 5, 16, 16, 100, 1);
	else if (occu == 2)player = Player(name, 100, 20, 3, 16, 16, 100, 2);
	else if (occu == 3) player = Player(name, 300, 40, 18, 16, 16, 100, 3);
	for (int i = 0; i < 5; i++)
	{
		player.addFood(foodList[0]);
	}
	for (int i = 0; i < 5; i++)player.addFood(foodList[1]);
		
}
void Dungeon::createItemList()
{
	weaponList.push_back(Item("Wood sword", "Equip", 0, 10, 0, 0, 0,20));
	weaponList.push_back(Item("Iron sword", "Equip", 0, 20, 0, 0, 0,30));
	weaponList.push_back(Item("Diamond sword", "Equip", 0, 30, 0, 0, 0,40));

	equipList.push_back(Item("Wood Armor", "Equip",30, 0, 5, 0, 0,20));
	equipList.push_back(Item("Iron Armor", "Equip", 40, 0, 10, 0, 0,30));
	equipList.push_back(Item("Diamond Armor", "Equip", 50, 0, 20, 0, 0,40));

	poisonList.push_back(Poison("Small Poison", 10, 0, 0, 2));
	poisonList.push_back(Poison("Normal Poison", 15, 0, 0, 3));
	poisonList.push_back(Poison("Scary Poison", 20, 0, 0, 4));
	
	foodList.push_back(Item("Bread", "Food", 0, 0, 0, 5, 0, 20));
	foodList.push_back(Item("Water", "Food", 0, 0, 0, 0, 5,20));
	foodList.push_back(Item("Milk", "Food", 0, 0, 0, 2, 3,30));
	foodList.push_back(Item("Apple", "Food", 30, 0, 0, 3, 3,40));
	foodList.push_back(Item("Golden Apple","Food", 50, 0, 0, 15, 15,70));

	foodList[2].setRemovePoison(1);
	foodList[4].setRemovePoison(1);

}
void Dungeon::createMap()
{
	for (int i = 0; i < 36; i++)rooms.push_back(Room());
	for (int i = 0; i < 9; i++)
	{
		int index = i + i / 3 * 3;
		int objectType = randomNum(50, 40, 10);
		if (objectType == 0)
		{
			NPC* N = new NPC("", "", {});
			int NPCtype = randomNum(40, 10, 50);
			if (NPCtype == 0)
			{
				*N = NPC("Trader", "Wanna buy something?", {});
				
					N->addCommodity(weaponList[randomNum(40, 40, 20)]);
					N->addCommodity(equipList[randomNum(40, 40, 20)]);
					N->addCommodity(foodList[randomNum(30, 30, 20, 15, 5)]);
					N->addCommodity(foodList[randomNum(30, 30, 20, 15, 5)]);
				
			}
			else if (NPCtype == 1)
			{
				*N = NPC("Mysterious Man", "Your will get either a poison or a good stuff, wanna try it?", {});
				int n = rand() % 4;
				if (n == 0)N->addCommodity(poisonList[randomNum(50, 30, 20)]);
				else if (n == 1)N->addCommodity(weaponList[randomNum(40, 40, 20)]);
				else if (n == 2)N->addCommodity(equipList[randomNum(40, 40, 20)]);
				else if (n == 3)N->addCommodity(foodList[randomNum(30, 30, 20, 15, 5)]);

			}
			else
			{
				*N = NPC("Friendly Villager", "Hello,my friend,wanna some good stuff？It's totally free", {});
				N->addCommodity(weaponList[randomNum(40, 40, 20)]);
				N->addCommodity(equipList[randomNum(40, 40, 20)]);
				N->addCommodity(foodList[randomNum(30, 30, 20, 15, 5)]);
				N->addCommodity(foodList[randomNum(30, 30, 20, 15, 5)]);

			}
			rooms[index]=(Room(0, index, 0, N, 1, 1));
		}
		else if (objectType == 1)
		{
			Monster* M = new Monster("Slime",50,20,0,10);
			rooms[index] = (Room(0, index, 0, M, 1, 1));
			int dropItem = rand() % 4;
			if (dropItem == 0)
			{
				rooms[index].addObjects(&weaponList[0]);
			}
			else if (dropItem == 1)
			{
				rooms[index].addObjects(&equipList[0]);
			}
			else if (dropItem == 2)
			{
				rooms[index].addObjects(&foodList[0]);
			}
			else if (dropItem == 3)
			{
				rooms[index].addObjects(&foodList[1]);
			}
			
		}
		else rooms[index] = (Room(0, index, 0, NULL, 1, 1));
		
	}
	for (int i = 0; i < 9; i++)
	{
		int index = i + 3 + i / 3 * 3;
		int objectType = randomNum(40, 40, 10,10);
		if (objectType == 0)
		{
			NPC* N = new NPC("", "", {});
			int NPCtype = randomNum(40, 10, 50);
			if (NPCtype == 0)
			{
				*N = NPC("Trader", "Wanna buy something?", {});
				for (int j = 0; j < 2; j++)
				{
					N->addCommodity(weaponList[randomNum(40, 40, 20)]);
					N->addCommodity(equipList[randomNum(40, 40, 20)]);
					N->addCommodity(foodList[randomNum(30, 30, 20, 15, 5)]);
					N->addCommodity(foodList[randomNum(30, 30, 20, 15, 5)]);
				}
			}
			else if (NPCtype == 1)
			{
				*N = NPC("Mysterious Man", "Your will get either a poison or a good stuff, wanna try it?", {});
				int n = rand() % 4;
				if (n == 0)N->addCommodity(poisonList[randomNum(50, 30, 20)]);
				else if (n == 1)N->addCommodity(weaponList[randomNum(40, 40, 20)]);
				else if (n == 2)N->addCommodity(equipList[randomNum(40, 40, 20)]);
				else if (n == 3)N->addCommodity(foodList[randomNum(30, 30, 20, 15, 5)]);

			}
			else
			{
				*N = NPC("Friendly Villager", "Hello,my friend,wanna some good stuff？It's totally free", {});
				N->addCommodity(weaponList[randomNum(40, 40, 20)]);
				N->addCommodity(equipList[randomNum(40, 40, 20)]);
				N->addCommodity(foodList[randomNum(30, 30, 20, 15, 5)]);
				N->addCommodity(foodList[randomNum(30, 30, 20, 15, 5)]);

			}
			rooms[index] = (Room(0, index, 1, N, 1, 2));
		}
		else if (objectType == 1)
		{
			Monster* M = new Monster("Desert Guardian", 100, 30, 10,20);
			M->addPoison(poisonList[0]);
			rooms[index]=(Room(0, index, 0, M, 1, 2));
			int r = randomNum(25, 25, 20, 20, 10);
			int r1 = rand() % 2;
			if (r == 0)
			{
				if (r1 == 0)rooms[index].addObjects(&weaponList[0]);
				else rooms[index].addObjects(&weaponList[1]);
			}
			else if (r == 1)
			{
				if (r1 == 0) rooms[index].addObjects(&equipList[0]);
				else rooms[index].addObjects(&equipList[1]);
			}
			else if (r == 2)
			{
				if (r1 == 0)rooms[index].addObjects(&foodList[0]);
				else rooms[index].addObjects(&foodList[3]);
			}
			else if (r == 3) rooms[index].addObjects(&foodList[1]);
			else rooms[index].addObjects(&foodList[2]);

		}
		else if (objectType == 2) rooms[index] = (Room(0, index, 1, NULL, 1, 2));
		else
		{
			
			rooms[index] = (Room(0, index, 1, &Oasis, 1, 2));
		}
	}
	for (int i = 0; i < 9; i++)
	{
		int index = i + 18 + i / 3 * 3;
		NPC* N = new NPC("Mysterious Man", "Your will get either a poison or a good stuff, wanna try it?", {});
		int r= randomNum(45, 25, 25, 5);
		int r1 = rand() % 2;
		if (r == 0)N->addCommodity(poisonList[1]);
		else if (r == 1)N->addCommodity(foodList[2]);
		else if (r == 2)
		{
			if (r1 == 0) N->addCommodity(weaponList[1]);
			else N->addCommodity(equipList[1]);
		}
		else
		{
			if (r1 == 0)N->addCommodity(weaponList[2]);
			else N->addCommodity(equipList[2]);
		}
		rooms[index] = (Room(0, index, 2, N, 0, 0));
	}
	for (int i = 0; i < 8; i++)
	{
		int index = i + 21 + i / 3 * 3;
		int objectType = randomNum(30, 60, 10);
		if (objectType == 0)
		{
			NPC* N = new NPC("", "", {});
			int NPCtype = randomNum(40, 10, 50);
			if (NPCtype == 0)
			{
				*N = NPC("Trader", "Wanna buy something?", {});
				for (int j = 0; j < 2; j++)
				{
					N->addCommodity(weaponList[randomNum(40, 40, 20)]);
					N->addCommodity(equipList[randomNum(40, 40, 20)]);
					N->addCommodity(foodList[randomNum(30, 30, 20, 15, 5)]);
					N->addCommodity(foodList[randomNum(30, 30, 20, 15, 5)]);
				}
			}
			else if (NPCtype == 1)
			{
				*N = NPC("Mysterious Man", "Your will get either a poison or a good stuff, wanna try it?", {});
				int n = rand() % 4;
				if (n == 0)N->addCommodity(poisonList[randomNum(50, 30, 20)]);
				else if (n == 1)N->addCommodity(weaponList[randomNum(40, 40, 20)]);
				else if (n == 2)N->addCommodity(equipList[randomNum(40, 40, 20)]);
				else if (n == 3)N->addCommodity(foodList[randomNum(30, 30, 20, 15, 5)]);

			}
			else
			{
				*N = NPC("Friendly Villager", "Hello,my friend,wanna some good stuff？It's totally free", {});
				N->addCommodity(weaponList[randomNum(40, 40, 20)]);
				N->addCommodity(equipList[randomNum(40, 40, 20)]);
				N->addCommodity(foodList[randomNum(30, 30, 20, 15, 5)]);
				N->addCommodity(foodList[randomNum(30, 30, 20, 15, 5)]);

			}
			rooms[index] = (Room(0, index, 3, N, 2, 1));
		}
		else if (objectType == 1)
		{

			int monsterType = randomNum(15, 15, 70);
			if (monsterType == 0)
			{
				Monster* M = new Monster("Bear", 300, 50, 30,50);
				M->addPoison(poisonList[1]);
				M->addPoison(poisonList[2]);
				rooms[index] = (Room(0, index, 3, M, 2, 1));
				int r = randomNum(25, 25, 50);
				if (r == 0) rooms[index].addObjects(&weaponList[2]);
				else if (r == 1) rooms[index].addObjects(&equipList[2]);
				else rooms[index].addObjects(&foodList[4]);
			}
			else if (monsterType == 1)
			{
				Monster* M = new Monster("Tiger", 200, 80, 20,50);
				M->addPoison(poisonList[1]);
				M->addPoison(poisonList[2]);
				rooms[index] = (Room(0, index, 3, M, 2, 1));
				int r = randomNum(25, 25, 50);
				if (r == 0) rooms[index].addObjects(&weaponList[2]);
				else if (r == 1) rooms[index].addObjects(&equipList[2]);
				else rooms[index].addObjects(&foodList[4]);
			}
			else if (monsterType == 2)
			{
				Monster* M = new Monster("Monkey", 120, 30, 15,30);
				rooms[index] = (Room(0, index, 3, M, 2, 1));
				rooms[index].addObjects(&foodList[3]);
			}
		}
		else
		{
			rooms[index] = (Room(0, index, 3, &Oasis, 2, 1));
		}
	}
	Monster* Boss =new Monster("Boss",800, 100, 50,10000);
	rooms[35]=(Room(1, 35, 3, Boss, 1, 1));

	for (int i = 0; i < 36; i++)
	{
		if (i % 6 != 0)rooms[i].setLeftRoom(&rooms[i - 1]);
		if (i % 6 != 5) rooms[i].setRightRoom(&rooms[i + 1]);
		if (i < 30)rooms[i].setDownROom(&rooms[i + 6]);
		if (i > 5)rooms[i].setUpRoom(&rooms[i - 6]);
	}
}

void Dungeon:: startGame()
{
	createItemList();
	createPlayer();
	
	createMap();
	player.setCurrentRoom(&rooms[0]);
	runDungeon();

}
void Dungeon::chooseAction()

{
	cout << "\nYou are in Room " << player.getCurrentRoom()->getIndex() << '\n';
	Room* curRoom = player.getCurrentRoom();
	cout << "Choose your action:\n";
	cout << "0. Show Status\n"
		<< "1. Go Up\n"
		<< "2. Go Down\n"
		<< "3. Go Left\n"
		<< "4. Go Right\n"
		<< "5. Eat Food\n";
	if (curRoom->getObjects().empty()
		||curRoom->getObjects()[0]->getName() == "Oasis" 
		|| curRoom->getObjects()[0]->getName() == "Lake"
		) {}
	else if (curRoom->getObjects()[0]->getTag() == "NPC")
	{
		cout << "6. Get someting from " << curRoom->getObjects()[0]->getName()<<'\n';
	}
	else if (curRoom->getObjects()[0]->getTag() == "Monster")
	{
		cout << "6. Fight " << curRoom->getObjects()[0]->getName() << '\n';
	}
	cout << "Choose your action:";
	int action;
	cin >> action;
	if (action == 0)
	{
		player.showStatus();
		chooseAction();
	}
	else if (action == 1)player.changeRoom(curRoom->getUpRoom());
	else if (action == 2)player.changeRoom(curRoom->getDownRoom());
	else if (action == 3)player.changeRoom(curRoom->getLeftRoom());
	else if (action == 4)player.changeRoom(curRoom->getRightRoom());
	else if (action == 5)
	{
		if (player.getFoods().empty())
		{
			cout << "No food in your bag\n";
			chooseAction();
		}
		player.showFood();
		cout << "Choose the food you want to eat,input 0 to exit: ";
		int foodAction;
		cin >> foodAction;

		if (foodAction == 0) chooseAction();
		else
		{
			while (foodAction > player.getFoods().size() || foodAction < 1)
			{
				cout << "Pls input valid number!";
				cin >> foodAction;
			}
			player.getFoods()[foodAction - 1].triggerEvent(&player);
			player.removeFood(foodAction - 1);
			chooseAction();
		}

	}
	else if (action == 6 && curRoom->getObjects()[0]->getTag() == "NPC")
	{
		int temp = curRoom->getObjects()[0]->triggerEvent(&player);
		if (temp == 1) curRoom->clearObject();
		else chooseAction();
	}
	else if (action == 6 && curRoom->getObjects()[0]->getTag() == "Monster")
	{
		int temp = curRoom->getObjects()[0]->triggerEvent(&player);
		if (temp == 1)
		{
			cout << "You Win!!\n";
			Monster* M = dynamic_cast<Monster*>(curRoom->getObjects()[0]);
			if (M->getName() == "Boss")
			{
				cout << "Congrats!!";
				exit(0);
			}
			cout << "You get " << curRoom->getObjects()[1]->getName() << " and " << M->getCoin() << " dollars\n";
			Item* i = dynamic_cast<Item*>(curRoom->getObjects()[1]);
			if ((*i).getType() == "Food") player.addFood((*i));
			else player.addItem(*i);
			player.setCoin(player.getCoin() + M->getCoin());
			curRoom->clearObject();
		}
		else
		{
			if (player.getCurrentHp() <= 0)
			{
				cout << "You lose!!";
				exit(0);
			}
			else
			{
				player.changeRoom(player.getPrevRoom());
				chooseAction();
			}
		}
	}
	else cout << "Invalid Number!!!\n";

}
void Dungeon::runDungeon()
{
	while (1)
	{
		
		hpCheck(player);
		player.runPoison();
		if (player.getCurrentRoom()->getRoomType() == 1)
		{
			int r3 = rand() % 10;
			if (r3 == 1)
			{
				cout << "You encounter StandStorm!!\n";
				cout << "Hunger-2, Thirst-2";
				player.setHunger(player.getHunger() - 1);
				player.setThirst(player.getThirst() - 1);
			}
		}
		if (player.getHunger() > 0) player.setHunger(player.getHunger() - player.getCurrentRoom()->getHungerDrop());
		else
		{
			cout << "Too Hungry!!! -5HP!!!\n";
			player.setCurrentHp(player.getCurrentHp() - 5);
		}
		if (player.getThirst() > 0)player.setThirst(player.getThirst() - player.getCurrentRoom()->getThirstDrop());
		else
		{
			cout << "Too Thirsty!!! -5HP!!!\n";
			player.setCurrentHp(player.getCurrentHp() - 5);
		}
		hpCheck(player);

		
		if (player.getCurrentRoom()->getObjects().empty())cout << "Looks like there is nothing in the room...\n";
		else if (player.getCurrentRoom()->getObjects()[0]->getName() == "Oasis"
			|| player.getCurrentRoom()->getObjects()[0]->getName() == "Lake")
		{
			cout << "You met " << player.getCurrentRoom()->getObjects()[0]->getName() << "!!!\n";
			cout << "Your thirst is full recover\n";
			player.setThirst(15);
		}
		chooseAction();
	}

}

void Dungeon:: hpCheck(Player p)
{
	if (p.getCurrentHp() <= 0)
	{
		cout << "You Lose!!";
		exit(0);
	}
}