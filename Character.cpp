#include "Character.h"

void Character::setupCharacter(char classID, int attributeArr[], sf::Texture& spriteTexture)
{
	this->characterSprite.setTexture(spriteTexture);
	switch (this->characterID)
	{
	case 'a':
		//dwarf
		this->characterSprite.setTextureRect(sf::IntRect(0, 48, 16, 16));

		break;
	case 'b':
		//elf
		this->characterSprite.setTextureRect(sf::IntRect(0, 0, 16, 16));

		break;
	case 'c':
		//gnome
		this->characterSprite.setTextureRect(sf::IntRect(112, 112, 16, 16));

		break;
	case 'd':
		//human
		this->characterSprite.setTextureRect(sf::IntRect(64, 0, 16, 16));
		
		break;
	case 'e':
		//orc
		this->characterSprite.setTextureRect(sf::IntRect(0, 32, 16, 16));

		break;
	}
	this->weaponItem = Item(classID);
	for (int i = 0; i < NUMBER_OF_ATTRIBUTES; i++)
		this->attributes[i] = attributeArr[i];
}

Character::Character()
{
	this->characterID = ' ';
	for (int i = 0; i < NUMBER_OF_ATTRIBUTES; i++)
		this->attributes[i] = 0;
}
Character::~Character()
{
}
int Character::getAttributeAtIndex(int index) const
{
	return this->attributes[index];
}
void Character::setAttributeAtIndex(int index, int attribute)
{
	this->attributes[index] = attribute;
}
void Character::create(char raceID, char classID, int attributeArr[], sf::Texture spriteTexture)
{
	this->characterID = raceID;
	this->setupCharacter(classID, attributeArr, spriteTexture);
	//location not set yet
	//inventory?
}
void Character::moveUp()
{
	//north
	this->location.y += t_size;
}
void Character::moveDown()
{
	//south
	this->location.y += t_size;
}
void Character::moveLeft()
{
	//west
	this->location.x += t_size;
}
void Character::moveRight()
{
	//east
	this->location.x += t_size;
}
sf::Vector2f Character::getLocation() const
{
	return this->location;
}
char Character::getID() const
{
	return this->characterID;
}
void Character::update()
{

	this->characterSprite.setPosition(this->location);
}
void Character::draw(sf::RenderWindow& gameWindow) const
{
	gameWindow.draw(this->characterSprite);
}