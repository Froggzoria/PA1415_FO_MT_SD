#include "CharacterManager.h"

CharacterManager::CharacterManager()
{
	this->charactersInGameSession = 0;
	if (!this->spriteTexture.loadFromFile("../Resources/roguelikecreatures.png"))
	{
		// Handle error
		exit(1);
	}
}
CharacterManager::~CharacterManager()
{
}
bool CharacterManager::makeCreation(char raceID, char classID, int attributeArr[])
{
	//FRÅGA MAX HÄR, VAD RETURNERAR DEN FÖR BOOL!?!?!??!?!??!!
	this->characters[this->charactersInGameSession++].create(raceID, classID, attributeArr, this->spriteTexture);
	return false;
}
bool CharacterManager::enterRoom(sf::Vector2f location, char characterID)
{

	return false;
}
int CharacterManager::attackPlayer(Item entityWeapon)
{
	return 0;
}
void CharacterManager::markPlayerDead()
{

}
void CharacterManager::update()
{
	for (int i = 0; i < this->charactersInGameSession; i++)
		this->characters[i].update();
}
void CharacterManager::draw(sf::RenderWindow & gameWindow) const
{
	for (int i = 0; i < this->charactersInGameSession; i++)
		this->characters[i].draw(gameWindow);
}