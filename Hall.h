#pragma once
#ifndef HALL_H
#define HALL_H


#include "Tile.h"
#include "RoomManager.h"
#include "Room.h"
#include <vector>
class RoomManager;

class Hall
{
private:
	std::vector<Tile*> hallway;
	sf::Vector2f startPoint;
	sf::Vector2f endPoint;

public:
	Hall();
	~Hall();
	void connectPoints(Room*, Room*, RoomManager&);
	void connectStairs(sf::Vector2f, sf::Vector2f, RoomManager&, sf::Texture*);
	void update();
	void draw(sf::RenderWindow&) const;
};

#endif // !HALL_H