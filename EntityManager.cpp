#include "EntityManager.h"

void EntityManager::expandEntities()
{
	this->capacity = this->capacity * 2;
	Entity* temp = new Entity[this->capacity];
	for (int i = 0; i < this->nrOfEntities; i++)
		temp[i] = this->entities[i];
	delete this->entities;
	this->entities = temp;
}

EntityManager::EntityManager()
{
	this->capacity = 20;
	this->entities = new Entity[this->capacity];
	this->nrOfEntities = 0;
	if (!this->spriteTexture.loadFromFile("../Resources/roguelikecreatures.png"))
	{
		// Handle error
		exit(1);
	}
}
EntityManager::~EntityManager()
{
	delete this->entities;
}
void EntityManager::startCombat(Entity entityID)
{
	entityID.startCombat();
}
void EntityManager::endCombat(Entity theEntity)
{
	theEntity.endCombat();
}
void EntityManager::startDialogue(Entity entityID)
{
	entityID.startDialogue();
}
void EntityManager::endDialogue(Entity theEntity)
{
	theEntity.endDialogue();
}
void EntityManager::update()
{
	for (int i = 0; i < this->nrOfEntities; i++)
		this->entities[i].update();
}
void EntityManager::draw(sf::RenderWindow& gameWindow) const
{
	for (int i = 0; i < this->nrOfEntities; i++)
		this->entities[i].draw(gameWindow);
}