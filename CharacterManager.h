#ifndef CHARACTERMANAGER_H
#define CHARACTERMANAGER_H
#include "Character.h"

static const int MAXIMUM_CHARACTERS = 4;

class CharacterManager
{
private:
	Character characters[MAXIMUM_CHARACTERS];
	int charactersInGameSession;
	sf::Texture spriteTexture;
public:
	CharacterManager();
	virtual ~CharacterManager();
	bool makeCreation(char raceID, char classID, int attributeArr[]);
	bool enterRoom(sf::Vector2f location, char characterID);
	int attackPlayer(Item entityWeapon);
	void markPlayerDead();
	void update();
	void draw(sf::RenderWindow& gameWindow) const;
};

#endif