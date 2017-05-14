#include "Tile.h"

void Tile::setSprite()
{
	switch (this->id)
	{
	case '.':
		this->tile.setTexture(*this->texture);
		this->tile.setTextureRect(sf::IntRect(0 * t_size, 2 * t_size, t_size, t_size));
		this->tile.setPosition(this->location);
		this->passable = true;
		this->stairCase = false;
		break;
	case '-':
		this->tile.setTexture(*this->texture);
		this->tile.setTextureRect(sf::IntRect(1 * t_size, 1 * t_size, t_size, t_size));
		this->tile.setPosition(this->location);
		this->passable = false;
		this->stairCase = false;
		break;
	case '|':
		this->tile.setTexture(*this->texture);
		this->tile.setTextureRect(sf::IntRect(2 * t_size, 0 * t_size, t_size, t_size));
		this->tile.setPosition(this->location);
		this->passable = false;
		this->stairCase = false;
		break;
	case '#':
		this->tile.setTexture(*this->texture);
		this->tile.setTextureRect(sf::IntRect(0 * t_size, 1 * t_size, t_size, t_size));
		this->tile.setPosition(this->location);
		this->passable = true;
		this->stairCase = false;
		break;
	case '>':
		this->tile.setTexture(*this->texture);
		this->tile.setTextureRect(sf::IntRect(8 * t_size, 4 * t_size, t_size, 2* t_size));
		this->tile.setPosition(this->location);
		this->passable = true;
		this->stairCase = true;
		break;
	case '<':
		this->tile.setTexture(*this->texture);
		this->tile.setTextureRect(sf::IntRect(7 * t_size, 4 * t_size, t_size, 2* t_size));
		this->tile.setPosition(this->location);
		this->passable = true;
		this->stairCase = true;
		break;
	default:
		break;
	}
}

Tile::Tile(char id, sf::Vector2f location, sf::Texture *texture)
{
	this->id = id;
	this->location = location;
	this->passable = false;
	this->texture = texture;
	this->setSprite();
}

Tile::~Tile()
{

}

sf::Vector2f Tile::getLocation() const
{
	return this->location;
}

char Tile::getID() const
{
	return this->id;
}

void Tile::update()
{
}

void Tile::draw(sf::RenderWindow &window) const
{
	window.draw(this->tile);
}
