#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"

const int INVENTORY_ROW = 6;
const int INVENTORY_COL = 5;

class Inventory
{
private:
	Item itemsInInventory[INVENTORY_COL * INVENTORY_ROW];
	int nrOfItems;
	bool isOpen;
public:
	Inventory();
	virtual ~Inventory();
	bool checkForKey(char keyID);
	bool roomLeft(Item itemSize);
	void addToInv(Item item);
	void openAndCloseInventory();
	void update();
	void draw(sf::RenderWindow& gameWindow) const;
};

#endif