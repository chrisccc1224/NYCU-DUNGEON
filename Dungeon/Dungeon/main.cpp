#include <iostream>
#include <string>
#include <vector>
#include "Dungeon.h"
#include "Item.h"
#include "Monster.h"
#include "NPC.h"
#include "Player.h"
#include"Random.h"
#include"Poison.h"
using namespace std;

int main() {
    srand(time(NULL));
    Dungeon dungeon = Dungeon();
    dungeon.startGame();
    system("pause");    
    return 0;
}
