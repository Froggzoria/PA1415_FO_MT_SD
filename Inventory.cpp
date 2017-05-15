#include "Inventory.h"

Inventory::Inventory()
{
	this->nrOfItems = 0;
	this->isOpen = false;
}
Inventory::~Inventory()
{
	delete this->itemsInInventory;
}
bool Inventory::checkForKey(char keyID)
{
	bool hasRequiredKey = false;

	for (int i = 0; i < this->nrOfItems && !hasRequiredKey; i++)
		if (this->itemsInInventory[i].getID() == keyID)
			hasRequiredKey = true;
	
	return hasRequiredKey;
}
bool Inventory::roomLeft(Item itemSize)
{
	bool spaceInBag = true;

	if (this->nrOfItems == INVENTORY_COL * INVENTORY_ROW)
		spaceInBag = false;

	return spaceInBag;
}
void Inventory::addToInv(Item item)
{
	this->itemsInInventory[this->nrOfItems++] = item;
}
void Inventory::openAndCloseInventory()
{
	if (this->isOpen)
		this->isOpen = false;
	else
		this->isOpen = true;
}
void Inventory::update()
{
	for (int i = 0; i < INVENTORY_ROW; i++)
		for (int k = 0; k < INVENTORY_COL; k++)
			this->itemsInInventory[k * i + k].setLocation(sf::Vector2f(64 + k * 16, 64 + i * 16));
}
void Inventory::draw(sf::RenderWindow& gameWindow) const
{
	if (this->isOpen)
		for (int i = 0; i < this->nrOfItems; i++)
			this->itemsInInventory[i].draw(gameWindow);
}