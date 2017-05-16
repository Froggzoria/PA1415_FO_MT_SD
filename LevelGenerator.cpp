#include "LevelGenerator.h"


std::string LevelGenerator::getDirectory()
{
	const unsigned long maxDir = 1024;
	char currentDir[maxDir];
	GetCurrentDirectoryA(maxDir, currentDir);
	return std::string(currentDir);
}

int LevelGenerator::getFrequency(std::string tweets,const std::string arr[], int size)
{
	int freq = 0;
	for (int i = 0; i < size; i++)
	{
		std::string s = arr[i];
		size_t nPos = tweets.find(s, 0);
		while (nPos != std::string::npos)
		{
			freq++;
			nPos = tweets.find(s, nPos + 1);
		}
	}
	return freq;
}

void LevelGenerator::addRooms()
{
	sf::Vector2f pos;
	for (int i = 0; i < NR_OF_DIFFERENT_ROOMS; i++)
	{
		switch (i)
		{
		case MONSTER_ROOM:
			pos.x = rand() % 94 + 3;
			pos.y = rand() % 55 + 2;
			pos.x *= t_size;
			pos.y *= t_size;
			for (int i = 0; i < this->keywordFreq[MONSTER_ROOM]; i++)
			{
				this->generated->addRoom(10, 10, pos);
				pos.x = rand() % 94 + 3;
				pos.y = rand() % 55 + 2;
				pos.x *= t_size;
				pos.y *= t_size;
			}
			break;
		case NPC_ROOM:
			pos.x = rand() % 94 + 3;
			pos.y = rand() % 55 + 2;
			pos.x *= t_size;
			pos.y *= t_size;
			for (int i = 0; i < this->keywordFreq[NPC_ROOM]; i++)
			{
				this->generated->addRoom(8, 8, pos);
				pos.x = rand() % 94 + 3;
				pos.y = rand() % 55 + 2;
				pos.x *= t_size;
				pos.y *= t_size;
			}
			break;
		case BOSS_ROOM:
			pos.x = rand() % 94 + 3;
			pos.y = rand() % 55 + 2;
			pos.x *= t_size;
			pos.y *= t_size;
			for (int i = 0; i < this->keywordFreq[BOSS_ROOM]; i++)
			{
				this->generated->addRoom(15, 15, pos);
				pos.x = rand() % 94 + 3;
				pos.y = rand() % 55 + 2;
				pos.x *= t_size;
				pos.y *= t_size;
			}
			break;
		case TREASURE_ROOM:
			pos.x = rand() % 94 + 3;
			pos.y = rand() % 55 + 2;
			pos.x *= t_size;
			pos.y *= t_size;
			for (int i = 0; i < this->keywordFreq[TREASURE_ROOM]; i++)
			{
				this->generated->addRoom(5, 5, pos);
				pos.x = rand() % 94 + 3;
				pos.y = rand() % 55 + 2;
				pos.x *= t_size;
				pos.y *= t_size;
			}
			break;
		default:
			break;
		}
	}
}

void LevelGenerator::addHalls()
{
	this->generated->addHalls(*this->generated);
}

void LevelGenerator::addStaircases()
{
	this->generated->addStaircases(*this->generated);
}

LevelGenerator::LevelGenerator()
{
	this->generated = new RoomManager();
	this->keywordFreq = new int[NR_OF_DIFFERENT_ROOMS];
	this->keywordFreq[NR_OF_DIFFERENT_ROOMS] = { 0 };
	for (int i = 0; i < NR_OF_DIFFERENT_ROOMS; i++)
		this->keywordFreq[i] = 0;
}

LevelGenerator::~LevelGenerator()
{
}

RoomManager * LevelGenerator::generateWithTwitter(std::vector<std::string> keywords)
{
	std::string s;
	for (unsigned i = 0; i < keywords.size(); i++)
		s += keywords.at(i) + "\n";

	std::ofstream oFile("keywords.txt", std::ofstream::out);
	oFile << s;
	oFile.close();
	
	std::string file_path = this->getDirectory(); //obtain solution dir path
	std::string file_name = "//twitter_api_script.pyw";
	std::string command = "python ";

	command = command + file_path + file_name;

	system(command.c_str()); //run python script

	//read in lines from generated tweet text file
	std::ifstream inFile("tweet_content.txt");

	std::string tweets = "";
	std::string strend = "[STREND]";
	while (tweets.find(strend) == std::string::npos)
	{
		std::string temp;
		std::getline(inFile, temp);
		tweets += temp;
	}

	this->keywordFreq[MONSTER_ROOM] = this->getFrequency(tweets, RESERVED_KEYWORDS_MONSTER, NR_OF_M_KEYWORDS);
	this->keywordFreq[NPC_ROOM] = this->getFrequency(tweets, RESERVED_KEYWORDS_NPC, NR_OF_NPC_KEYWORDS);
	this->keywordFreq[BOSS_ROOM] = this->getFrequency(tweets, RESERVED_KEYWORDS_BOSS, NR_OF_BOSS_KEYWORDS);
	this->keywordFreq[TREASURE_ROOM] = this->getFrequency(tweets, RESERVED_KEYWORDS_TREASURE, NR_OF_TRS_KEYWORDS);

	this->addRooms();
	this->addHalls();
	this->addStaircases();

	return this->generated;
}

RoomManager * LevelGenerator::generateOffline()
{
	
	int randIndex = rand() % 4;
	int takenIndex[NR_OF_DIFFERENT_ROOMS] = { 0 };
	for (int i = 0; i < NR_OF_DIFFERENT_ROOMS; i++)
		takenIndex[i] = -1;

	int maxNrRooms = 10;
	int nrOfRooms = 0;

	while (nrOfRooms < maxNrRooms)
	{
		switch (randIndex)
		{
		case 0:
			if (takenIndex[0] != 0)
			{
				this->keywordFreq[0] += rand()%3 + 1;
				takenIndex[0] = 0;
				nrOfRooms += this->keywordFreq[0];
			}
			break;
		case 1:
			if (takenIndex[1] != 1)
			{
				this->keywordFreq[1] += rand() % 3 + 1;
				takenIndex[1] = 1;
				nrOfRooms += this->keywordFreq[1];
			}
			break;
		case 2:
			if (takenIndex[2] != 2)
			{
				this->keywordFreq[2] += rand() % 2 + 1;
				takenIndex[2] = 2;
				nrOfRooms += this->keywordFreq[2];
			}
			break;
		case 3:
			if (takenIndex[3] != 3)
			{
				this->keywordFreq[3] += rand() % 3 + 1;
				takenIndex[3] = 3;
				nrOfRooms += this->keywordFreq[3];
			}
			break;
		}

		
		int ctr = 0;
		for (int i = 0; i < NR_OF_DIFFERENT_ROOMS; i++)
		{
			if (takenIndex[i] == -1)
				ctr++;
		}

		if (nrOfRooms < maxNrRooms && ctr == 0)
		{
			for (int i = 0; i < NR_OF_DIFFERENT_ROOMS; i++)
			{
				takenIndex[i] = -1;
			}
		}

		randIndex = rand() % 4;
	}
	
	this->addRooms();
	this->addHalls();
	this->addStaircases();
	
	for (int i = 0; i < 4; i++)
		std::cout << this->keywordFreq[i];
	
	return this->generated;
}
