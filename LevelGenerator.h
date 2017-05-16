#ifndef LEVELGENERATOR_H
#define LEVELGENERATOR_H


#include "RoomManager.h"
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>
#include <iostream>


#define MONSTER_ROOM 0
#define NPC_ROOM 1
#define BOSS_ROOM 2
#define TREASURE_ROOM 3

#define NR_OF_DIFFERENT_ROOMS 4

#define NR_OF_M_KEYWORDS 6
#define NR_OF_NPC_KEYWORDS 3
#define NR_OF_BOSS_KEYWORDS 4
#define NR_OF_TRS_KEYWORDS 10

const std::string RESERVED_KEYWORDS_MONSTER[NR_OF_M_KEYWORDS] = { "nomral", "monster", "scary", "minion", "fight", "battle" };
const std::string RESERVED_KEYWORDS_NPC[NR_OF_NPC_KEYWORDS] = { "trade", "conversation", "friend" };
const std::string RESERVED_KEYWORDS_BOSS[NR_OF_BOSS_KEYWORDS] = { "boss", "Russia", "elite", "torment" };
const std::string RESERVED_KEYWORDS_TREASURE[NR_OF_TRS_KEYWORDS] = { "treasure", "precious", "gold", "money", "chest", "amulet", "crown", "loot", "ring", "key" };

class LevelGenerator
{
private:
	RoomManager* generated;
	int *keywordFreq;
	std::string getDirectory();
	int getFrequency(std::string,const std::string[], int size);
	void addRooms();
	void addHalls();
	void addStaircases();
public:
	LevelGenerator();
	~LevelGenerator();

	RoomManager* generateWithTwitter(std::vector<std::string>);
	RoomManager* generateOffline();

};
#endif // !LEVELGENERATOR_H
