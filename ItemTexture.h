#ifndef ITEMTEXTURE_H
#define ITEMTEXTURE_H
#include <SFML\Graphics.hpp>

class ItemTexture
{
private:
	sf::Texture itemTexture;
public:
	ItemTexture();
	virtual ~ItemTexture();
	sf::Texture& getItemTexture();
};

#endif