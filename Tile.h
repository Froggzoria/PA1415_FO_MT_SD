#pragma once
#ifndef TILE_H
#define TILE_H
#include "GameObject.h"
#include <stdlib.h>

const int t_size = 16;

class Tile : public GameObject
{
private:
	char id;
	sf::Sprite tile;
	bool passable;
	bool stairCase;
	sf::Vector2f location;
	sf::Texture *texture;
	void setSprite();


public:

	Tile(char, sf::Vector2f, sf::Texture*);
	~Tile();
	sf::Vector2f getLocation() const;
	char getID() const;
	void update();
	void draw(sf::RenderWindow&) const;
};

#endif //TILE_H
