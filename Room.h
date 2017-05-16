#ifndef ROOM_H
#define ROOM_H


#include"Tile.h"
#include<map>
#include<math.h>

class Room
{
private:
	Tile ***map;
	int rows;
	int columns;
	sf::Vector2f location;
	sf::Vector2f doorLocation;
	sf::Texture *texture;
	void buildRoom();
	/*bool addDoor(int, int);*/

public:
	Room(int, int, sf::Vector2f, sf::Texture*);
	~Room();
	sf::Vector2f getDoorLocation() const;
	sf::Texture* getTexture() const;
	bool checkSpace(sf::Vector2f) const;


	void update();
	void draw(sf::RenderWindow&) const;

};

#endif // !ROOM_H