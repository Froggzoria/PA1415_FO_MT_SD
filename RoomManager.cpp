#include "RoomManager.h"

RoomManager::RoomManager()
{
	this->texture = new sf::Texture();
	this->texture2 = new sf::Texture();

	if (!this->texture->loadFromFile("rogueliketiles.png"))
	{
		exit(1);
	}
	if (!this->texture2->loadFromFile("dungeon_tileset.png"))
	{
		exit(1);
	}
}

RoomManager::~RoomManager()
{
}

void RoomManager::addRoom(int r, int c, sf::Vector2f l)
{
	Room *newRoom = new Room(r, c, l, this->texture);
	this->rooms.insert(this->rooms.begin(), newRoom);
}

void RoomManager::addHalls(RoomManager &manager)
{
	for (unsigned i = 0; i < rooms.size(); i++)
	{
		for (unsigned j = 0; j < rooms.size(); j++)
		{
			if (i != j)
			{
				Hall * hall = new Hall();
				hall->connectPoints(rooms.at(i), rooms.at(j), manager);
				this->halls.insert(halls.begin(), hall);
				hall = nullptr;
			}
		}
	}
}

void RoomManager::addStaircases(RoomManager &manager)
{
	sf::Vector2f down;
	down.x = 0;
	down.y = 960/2;

	sf::Vector2f up;
	up.x = 1600 - t_size;
	up.y = 960/2;

	this->staircases[0] = new Tile('>', down, this->texture2);
	this->staircases[1] = new Tile('<', up, this->texture2);

	Hall * hall = new Hall();
	hall->connectStairs(down, up, manager, this->texture);
	this->halls.insert(halls.begin(), hall);
	hall = nullptr;

	hall = new Hall();
	hall->connectStairs(up, down, manager, this->texture);
	this->halls.insert(halls.begin(), hall);
	hall = nullptr;

}

bool RoomManager::checkSpace(sf::Vector2f loc) const
{
	bool space = false;
	for (unsigned i = 0; i < rooms.size(); i++)
	{
		space = rooms.at(i)->checkSpace(loc);
		if (!space)
			i = rooms.size();

	}

	return space;
}

void RoomManager::draw(sf::RenderWindow &window) const
{
	for (unsigned i = 0; i < this->rooms.size(); i++)
	{
		this->rooms.at(i)->draw(window);
	}
	for (unsigned i = 0; i < this->halls.size(); i++)
	{
		this->halls.at(i)->draw(window);
	}
	this->staircases[0]->draw(window);
	this->staircases[1]->draw(window);
}

void RoomManager::update()
{
	for (unsigned i = 0; i < this->rooms.size(); i++)
	{
		this->rooms.at(i)->update();
	}
}
