#include "ItemTexture.h"

ItemTexture::ItemTexture()
{
	if (!this->itemTexture.loadFromFile("../Resources/roguelikeitems.png"))
	{
		// Handle error
		exit(1);
	}
}
ItemTexture::~ItemTexture()
{
}
sf::Texture& ItemTexture::getItemTexture()
{
	return this->itemTexture;
}