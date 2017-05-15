#include "Entity.h"

void Entity::setupEntity(char entityID, sf::Texture& spriteTexture, int healthPoints, sf::Vector2f location)
{
	this->entityID = entityID;
	switch (this->entityID)
	{
	case '1':
		//blue bug
		this->entitySprite.setTexture(spriteTexture);
		this->entitySprite.setTextureRect(sf::IntRect(0, 80, 16, 16));

		break;
	case '2':
		//red bug
		this->entitySprite.setTexture(spriteTexture);
		this->entitySprite.setTextureRect(sf::IntRect(32, 80, 16, 16));

		break;
	case '3':
		//ice blue bug
		this->entitySprite.setTexture(spriteTexture);
		this->entitySprite.setTextureRect(sf::IntRect(64, 80, 16, 16));

		break;
	case '4':
		//bat
		this->entitySprite.setTexture(spriteTexture);
		this->entitySprite.setTextureRect(sf::IntRect(64, 64, 16, 16));

		break;
	case '5':
		//ghost
		this->entitySprite.setTexture(spriteTexture);
		this->entitySprite.setTextureRect(sf::IntRect(0, 112, 16, 16));

		break;
	case '6':
		//blob
		this->entitySprite.setTexture(spriteTexture);
		this->entitySprite.setTextureRect(sf::IntRect(0, 128, 16, 16));

		break;
	}
	this->healthPoints = healthPoints;
	this->location = location;
	this->inCombat = false;
	this->inDialogue = false;
}

Entity::Entity()
{
	this->entityID = ' ';
	this->inCombat = false;
	this->inDialogue = false;
	this->healthPoints = 0;
}
Entity::Entity(char entityID, sf::Texture& spriteTexture, int healthPoints, sf::Vector2f location)
{
	this->setupEntity(entityID, spriteTexture, healthPoints, location);
}
Entity::Entity(char entityID, sf::Texture& spriteTexture, int healthPoints, sf::Vector2f location, Item weaponItem)
{
	this->weaponItem = weaponItem;
	this->setupEntity(entityID, spriteTexture, healthPoints, location);
}
Entity::~Entity()
{
}
bool Entity::getInCombat() const
{
	return this->inCombat;
}
Item Entity::getEntityWeapon() const
{
	return this->weaponItem;
}
int Entity::getHealthPoints()
{
	return this->healthPoints;
}
sf::Vector2f Entity::getLocation() const
{
	return this->location;
}
char Entity::getID() const
{
	return this->entityID;
}
bool Entity::startCombat()
{
	this->inCombat = true;
	return this->inCombat;
}
bool Entity::endCombat()
{
	this->inCombat = false;
	return this->inCombat;
}
bool Entity::startDialogue()
{
	this->inDialogue = true;
	return this->inDialogue;
}
bool Entity::endDialogue()
{
	this->inDialogue = false;
	return this->inDialogue;
}
void Entity::attack(Item characterItem)
{

}
void Entity::update()
{
	this->entitySprite.setPosition(this->location);
}
void Entity::draw(sf::RenderWindow& gameWindow) const
{
	gameWindow.draw(this->entitySprite);
}