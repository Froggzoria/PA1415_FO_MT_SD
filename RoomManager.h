#pragma once
#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H

#include "Hall.h"
class Room;
class Hall;

class RoomManager
{
private:
	std::vector<Room*> rooms;
	std::vector<Hall*> halls;
	sf::Texture *texture;
	sf::Texture *texture2;
	Tile* staircases[2];

public:
	RoomManager();
	~RoomManager();

	void addRoom(int, int, sf::Vector2f);
	void addHalls(RoomManager&);
	void addStaircases(RoomManager&);
	bool checkSpace(sf::Vector2f) const;
	void draw(sf::RenderWindow&) const;
	void update();
};
#endif // !ROOMMANAGER_H