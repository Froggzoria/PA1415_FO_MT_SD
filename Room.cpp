#include "Room.h"

void Room::buildRoom()
{
	bool hasDoor = false;
	int sideOfDoor = rand() % 5 + 1;
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 1; j < this->columns; j++)
		{
			if (i == 0 || i == (this->rows - 1) || j == 1 || j == (this->columns - 1))
			{
				/*if ((i == 0 && j == columns/2 && !hasDoor) || (i == rows/2 && j == 1 && !hasDoor) || (i == rows -1 && j == columns/2 && !hasDoor) || (i == rows/2 && j == columns-1 && !hasDoor))
				{
					hasDoor = addDoor(i, j);
				}*/
				if (i == rows / 2 && j == columns - 1) {
					this->map[i][j] = new Tile('|', sf::Vector2f(location.x + i * t_size, location.y + (j - 1) * t_size), this->texture);
					this->doorLocation.x = location.x + i * t_size;
					this->doorLocation.y = location.y + (j - 1) * t_size;
				}
				else
					this->map[i][j] = new Tile('-', sf::Vector2f(location.x + i * t_size, location.y + (j-1) * t_size), this->texture);
			}
			else
			{
				this->map[i][j] = new Tile('.', sf::Vector2f(location.x + i * t_size, location.y + (j-1) * t_size), this->texture);
			}
		}
	}
}

//bool Room::addDoor(int i, int j)
//{
//	bool doorAdded = false;
//	if (i == 0)
//	{
//		if (location.x >= t_size)
//		{
//			this->map[i][j] = new Tile('|', sf::Vector2f(location.x + i * t_size, location.y + (j - 1) * t_size), this->texture);
//			doorAdded = true;
//		}
//	}
//	else if (i == rows / 2)
//	{
//		if (j == 1 && location.y >= t_size)
//		{
//			this->map[i][j] = new Tile('|', sf::Vector2f(location.x + i * t_size, location.y + (j - 1) * t_size), this->texture);
//			doorAdded = true;
//		}
//		else if (j == columns - 1 && 960 - location.y >= t_size)
//		{
//			this->map[i][j] = new Tile('|', sf::Vector2f(location.x + i * t_size, location.y + (j - 1) * t_size), this->texture);
//			doorAdded = true;
//		}
//	}
//	else if (i == rows - 1)
//	{
//		if (1600 - location.x >= t_size)
//		{
//			this->map[i][j] = new Tile('|', sf::Vector2f(location.x + i * t_size, location.y + (j - 1) * t_size), this->texture);
//			doorAdded = true;
//		}
//	}
//	return doorAdded;
//}

Room::Room(int rows, int columns, sf::Vector2f location, sf::Texture *texture)
{
	this->rows = rows;
	this->columns = columns + 1;
	this->location = location;
	this->texture = texture;
	this->map = new Tile**[rows];
	for (int i = 0; i < rows; i++)
	{
		this->map[i] = new Tile*[columns + 1];
	}
	buildRoom();
}

Room::~Room()
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 1; j < this->columns; j++)
		{
			delete this->map[i][j];
		}
		delete this->map[i];
	}
	delete this->map;
}

sf::Vector2f Room::getDoorLocation() const
{
	return this->doorLocation;
}

sf::Texture * Room::getTexture() const
{
	return this->texture;
}

bool Room::checkSpace(sf::Vector2f tile) const
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 1; j < columns; j++)
		{
			if (tile.x == map[i][j]->getLocation().x && tile.y == map[i][j]->getLocation().y)
				return false;
		}
	}
	return true;
}

void Room::update()
{
}

void Room::draw(sf::RenderWindow &window) const
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 1; j < this->columns; j++)
		{
			this->map[i][j]->draw(window);
		}
	}
}
