#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include "Entity.h"

class EntityManager
{
private:
	Entity* entities;
	int capacity;
	int nrOfEntities;
	sf::Texture spriteTexture;

	void expandEntities();
public:
	EntityManager();
	virtual ~EntityManager();
	void startCombat(Entity entityID);
	void endCombat(Entity theEntity);
	void startDialogue(Entity entityID);
	void endDialogue(Entity theEntity);
	void update();
	void draw(sf::RenderWindow& gameWindow) const;
};

#endif