#ifndef CHARACTER_H
#define CHARACTER_H
#include "Inventory.h"

static const int NUMBER_OF_ATTRIBUTES = 6;

class Character : public GameObject
{
private:
	char characterID;
	int attributes[NUMBER_OF_ATTRIBUTES];
	Inventory characterInventory;
	Item weaponItem;
	sf::Sprite characterSprite;
	sf::Vector2f location;

	void setupCharacter(char classID, int attributeArr[], sf::Texture& spriteTexture);
public:
	Character();
	virtual ~Character();
	int getAttributeAtIndex(int index) const;
	sf::Vector2f getLocation() const;
	char getID() const;
	void setAttributeAtIndex(int index, int attribute);
	void create(char raceID, char classID, int attributeArr[], sf::Texture spriteTexture);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void update();
	void draw(sf::RenderWindow& gameWindow) const;
};

#endif