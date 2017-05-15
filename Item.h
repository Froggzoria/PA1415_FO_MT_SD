#ifndef ITEM_H
#define ITEM_H
#include "GameObject.h"
#include "ItemTexture.h"

class Item : public GameObject
{
private:
	char itemID;
	bool isPickedUp;
	//int attributes[NUMBER_OF_ATTRIBUTES];
	sf::Sprite itemSprite;
	sf::Vector2f location;
	static ItemTexture itemTexture;

	void createItem();
public:
	Item();
	Item(char itemID);
	virtual ~Item();
	sf::Vector2f getLocation() const;
	void setLocation(sf::Vector2f location);
	void pickUpItem();
	char getID() const;
	void update();
	void draw(sf::RenderWindow& gameWindow) const;
};

#endif