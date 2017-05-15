#ifndef ENTITY_H
#define ENTITY_H
#include "Item.h"

class Entity : public GameObject
{
private:
	char entityID;
	bool inCombat;
	bool inDialogue;
	Item weaponItem;
	int healthPoints;
	sf::Sprite entitySprite;
	sf::Vector2f location;

	void setupEntity(char entityID, sf::Texture& spriteTexture, int healthPoints, sf::Vector2f location);
public:
	Entity();
	Entity(char entityID, sf::Texture& spriteTexture, int healthPoints, sf::Vector2f location);
	Entity(char entityID, sf::Texture& spriteTexture, int healthPoints, sf::Vector2f location, Item weaponItem);
	virtual ~Entity();
	bool getInCombat() const;
	Item getEntityWeapon() const;
	int getHealthPoints();
	sf::Vector2f getLocation() const;
	char getID() const;
	bool startCombat();
	bool endCombat();
	bool startDialogue();
	bool endDialogue();
	void attack(Item characterItem);
	void update();
	void draw(sf::RenderWindow& gameWindow) const;
};

#endif