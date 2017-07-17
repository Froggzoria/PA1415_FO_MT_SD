#include <SFML\Graphics.hpp>


class GameObject
{
public:
	virtual sf::Vector2f getLocation() const = 0;
	virtual char getID() const = 0;
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow&) const = 0;
};
