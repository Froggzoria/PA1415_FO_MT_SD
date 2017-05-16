#include "Hall.h"

Hall::Hall()
{
}

Hall::~Hall()
{
}

void Hall::connectPoints(Room* start, Room* end, RoomManager &manager)
{
	int north = -t_size;
	int south = t_size;
	int west = -t_size;
	int east = t_size;

	this->startPoint = start->getDoorLocation();
	this->endPoint = end->getDoorLocation();

	sf::Texture * texture = start->getTexture();

	float dx = startPoint.x - endPoint.x;
	float dy = startPoint.y - endPoint.y;
	
	sf::Vector2f currentLocation;
	currentLocation.x = startPoint.x;
	currentLocation.y = startPoint.y + t_size;

	sf::Vector2f goalLocation;
	goalLocation.x = endPoint.x;
	goalLocation.y = endPoint.y + t_size;

	Tile* tile = new Tile('#', currentLocation, texture);
	this->hallway.insert(this->hallway.begin(), tile);
	tile = nullptr;

	while (currentLocation.x != goalLocation.x || currentLocation.y != goalLocation.y)
	{
		if (dy < 0)
		{
			sf::Vector2f newLocation;
			newLocation.x = currentLocation.x;
			newLocation.y = currentLocation.y + south;
			if (dy < 0 && manager.checkSpace(newLocation))
			{
				currentLocation.y += south;
				dy += south;
				tile = new Tile('#', currentLocation, texture);
				this->hallway.insert(this->hallway.begin(), tile);
				tile = nullptr;
			}
			else
				dy += south;
		}
		else if (dx < 0)
		{
			sf::Vector2f newLocation;
			newLocation.x = currentLocation.x + east;
			newLocation.y = currentLocation.y;
			if (manager.checkSpace(newLocation))
			{
				currentLocation.x += east;
				dx += east;
				tile = new Tile('#', currentLocation, texture);
				this->hallway.insert(this->hallway.begin(), tile);
				tile = nullptr;
			}
			else
				dx += east;
		}
		else if (dy > 0)
		{
			sf::Vector2f newLocation;
			newLocation.x = currentLocation.x;
			newLocation.y = currentLocation.y + north;
			if (manager.checkSpace(newLocation))
			{
				currentLocation.y += north;
				dy += north;
				tile = new Tile('#', currentLocation, texture);
				this->hallway.insert(this->hallway.begin(), tile);
				tile = nullptr;
			}
			else
				dy += north;
		}
		else if (dx > 0)
		{
			sf::Vector2f newLocation;
			newLocation.x = currentLocation.x + west;
			newLocation.y = currentLocation.y;
			if (manager.checkSpace(newLocation))
			{
				currentLocation.x += west;
				dx += west;
				tile = new Tile('#', currentLocation, texture);
				this->hallway.insert(this->hallway.begin(), tile);
				tile = nullptr;
			}
			else
				dx += west;
		}
		else
		{
			currentLocation.x = goalLocation.x;
			currentLocation.y = goalLocation.y;
		}
	}
}

void Hall::connectStairs(sf::Vector2f down, sf::Vector2f up, RoomManager &manager, sf::Texture *texture)
{
	int north = -t_size;
	int south = t_size;
	int west = -t_size;
	int east = t_size;

	this->startPoint = down;
	this->endPoint = up;

	float dx = (startPoint.x + t_size) - (endPoint.x - t_size);
	float dy = (startPoint.y + t_size) - (endPoint.y + t_size);

	sf::Vector2f currentLocation;
	currentLocation.x = startPoint.x;
	currentLocation.y = startPoint.y + t_size;

	sf::Vector2f goalLocation;
	goalLocation.x = endPoint.x;
	goalLocation.y = endPoint.y;

	Tile* tile = new Tile('#', currentLocation, texture);
	this->hallway.insert(this->hallway.begin(), tile);
	tile = nullptr;

	while (currentLocation.x != goalLocation.x || currentLocation.y != goalLocation.y)
	{
		if (dy < 0)
		{
			sf::Vector2f newLocation;
			newLocation.x = currentLocation.x;
			newLocation.y = currentLocation.y + south;
			dy += south;
			if (dy < 0 && manager.checkSpace(newLocation))
			{
				currentLocation.y += south;
				dy += south;
				tile = new Tile('#', currentLocation, texture);
				this->hallway.insert(this->hallway.begin(), tile);
				tile = nullptr;
			}
		}
		else if (dx < 0)
		{
			sf::Vector2f newLocation;
			newLocation.x = currentLocation.x + east;
			newLocation.y = currentLocation.y;
			dx += east;
			if (manager.checkSpace(newLocation))
			{
				currentLocation.x += east;
				dx += east;
				tile = new Tile('#', currentLocation, texture);
				this->hallway.insert(this->hallway.begin(), tile);
				tile = nullptr;
			}
		}
		else if (dy > 0)
		{
			sf::Vector2f newLocation;
			newLocation.x = currentLocation.x;
			newLocation.y = currentLocation.y + north;
			if (manager.checkSpace(newLocation))
			{
				currentLocation.y += north;
				dy += north;
				tile = new Tile('#', currentLocation, texture);
				this->hallway.insert(this->hallway.begin(), tile);
				tile = nullptr;
			}
			else
				dy += north;
		}
		else if (dx > 0)
		{
			sf::Vector2f newLocation;
			newLocation.x = currentLocation.x + west;
			newLocation.y = currentLocation.y;
			if (manager.checkSpace(newLocation))
			{
				currentLocation.x += west;
				dx += west;
				tile = new Tile('#', currentLocation, texture);
				this->hallway.insert(this->hallway.begin(), tile);
				tile = nullptr;
			}
			else
				dx += west;
		}
		else
		{
			currentLocation.x = goalLocation.x;
			currentLocation.y = goalLocation.y;
		}
	}
}

void Hall::update()
{
}

void Hall::draw(sf::RenderWindow &window) const
{
	for (unsigned i = 0; i < this->hallway.size(); i++)
	{
		this->hallway.at(i)->draw(window);
	}
}
