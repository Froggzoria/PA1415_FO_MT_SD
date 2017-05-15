#include "Item.h"

void Item::createItem()
{
	switch (this->itemID)
	{
	case '1':
		//key one
		this->itemSprite.setTexture(this->itemTexture.getItemTexture());
		this->itemSprite.setTextureRect(sf::IntRect(192, 32, 16, 16));
		break;
	case '2':
		//key two
		this->itemSprite.setTexture(this->itemTexture.getItemTexture());
		this->itemSprite.setTextureRect(sf::IntRect(176, 48, 16, 16));
		break;
	case '3':
		//key three
		this->itemSprite.setTexture(this->itemTexture.getItemTexture());
		this->itemSprite.setTextureRect(sf::IntRect(192, 48, 16, 16));
		break;
	case 'a':
		//spade
		this->itemSprite.setTexture(this->itemTexture.getItemTexture());
		this->itemSprite.setTextureRect(sf::IntRect(64, 96, 16, 16));
		break;
	case 'b':
		//greatsword
		this->itemSprite.setTexture(this->itemTexture.getItemTexture());
		this->itemSprite.setTextureRect(sf::IntRect(16, 128, 16, 16));
		break;
	case 'c':
		//piece of wood
		this->itemSprite.setTexture(this->itemTexture.getItemTexture());
		this->itemSprite.setTextureRect(sf::IntRect(112, 96, 16, 16));
		break;
	case 'd':
		//leaf
		this->itemSprite.setTexture(this->itemTexture.getItemTexture());
		this->itemSprite.setTextureRect(sf::IntRect(0, 192, 16, 16));
		break;
	case 'e':
		//axe
		this->itemSprite.setTexture(this->itemTexture.getItemTexture());
		this->itemSprite.setTextureRect(sf::IntRect(160, 96, 16, 16));
		break;
	case 'f':
		//gloves
		this->itemSprite.setTexture(this->itemTexture.getItemTexture());
		this->itemSprite.setTextureRect(sf::IntRect(160, 144, 16, 16));
		break;
	case 'g':
		//scepter
		this->itemSprite.setTexture(this->itemTexture.getItemTexture());
		this->itemSprite.setTextureRect(sf::IntRect(48, 176, 16, 16));
		break;
	case 'h':
		//bow
		this->itemSprite.setTexture(this->itemTexture.getItemTexture());
		this->itemSprite.setTextureRect(sf::IntRect(176, 144, 16, 16));
		break;
	case 'i':
		//dagger
		this->itemSprite.setTexture(this->itemTexture.getItemTexture());
		this->itemSprite.setTextureRect(sf::IntRect(192, 128, 16, 16));
		break;
	case 'j':
		//sword
		this->itemSprite.setTexture(this->itemTexture.getItemTexture());
		this->itemSprite.setTextureRect(sf::IntRect(0, 112, 16, 16));
		break;
	case 'k':
		//dice
		this->itemSprite.setTexture(this->itemTexture.getItemTexture());
		this->itemSprite.setTextureRect(sf::IntRect(192, 176, 16, 16));
		break;
	case 'l':
		//spear
		this->itemSprite.setTexture(this->itemTexture.getItemTexture());
		this->itemSprite.setTextureRect(sf::IntRect(80, 112, 16, 16));
		break;
	case 'm':
		//tome
		this->itemSprite.setTexture(this->itemTexture.getItemTexture());
		this->itemSprite.setTextureRect(sf::IntRect(160, 208, 16, 16));
		break;
	case '4':
		//pickaxe
		this->itemSprite.setTexture(this->itemTexture.getItemTexture());
		this->itemSprite.setTextureRect(sf::IntRect(80, 96, 16, 16));
		break;
	case '5':
		//club
		this->itemSprite.setTexture(this->itemTexture.getItemTexture());
		this->itemSprite.setTextureRect(sf::IntRect(96, 112, 16, 16));
		break;
	case '6':
		//mace
		this->itemSprite.setTexture(this->itemTexture.getItemTexture());
		this->itemSprite.setTextureRect(sf::IntRect(112, 128, 16, 16));
		break;
	case '7':
		//mushroom
		this->itemSprite.setTexture(this->itemTexture.getItemTexture());
		this->itemSprite.setTextureRect(sf::IntRect(64, 192, 16, 16));
		break;
	case '8':
		//potion
		this->itemSprite.setTexture(this->itemTexture.getItemTexture());
		this->itemSprite.setTextureRect(sf::IntRect(176, 64, 16, 16));
		break;
	case ' ':
		//empty
		this->itemSprite.setTexture(this->itemTexture.getItemTexture());
		this->itemSprite.setTextureRect(sf::IntRect(160, 176, 16, 16));
	}
}

Item::Item()
{
	this->itemID = ' ';
	this->isPickedUp = true;
}
Item::Item(char itemID)
{
	this->itemID = itemID;
	this->isPickedUp = false;
	this->createItem();
}
Item::~Item()
{
}
void Item::pickUpItem()
{
	if (!this->isPickedUp)
		this->isPickedUp = true;
}
sf::Vector2f Item::getLocation() const
{
	return this->location;
}
void Item::setLocation(sf::Vector2f location)
{
	this->location = location;
}
char Item::getID() const
{
	return this->itemID;
}
void Item::update()
{
	//if picked up send UDP message
	this->itemSprite.setPosition(this->location);
}
void Item::draw(sf::RenderWindow& gameWindow) const
{
	if (!this->isPickedUp)
		gameWindow.draw(this->itemSprite);
}