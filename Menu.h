#ifndef MENU_H
#define MENU_H
#include"SFML\Graphics.hpp"
#include<string>
#include<Windows.h>
//-----TEMP CONSOLE-----
#include<iostream>
//-----TENO CONSOLE-----

static const int MENU_SIZE = 5;

class Menu : public sf::Drawable
{
private:
	sf::Font fnt0;
	sf::Text menuItems[MENU_SIZE];
	sf::Texture bImage;
	sf::Sprite background;
	int nrOfOptions;
	int currentOption;
	int selectedOption;


	void initializeVariables();
	void buildMenu();
	void loadFont();
	void loadBackground();
public:
	Menu();
	~Menu();

	sf::Texture& getBackgroundImg();
	void selectOption();
	void updateCurrent(sf::Vector2i mousePos);
	int update(sf::Vector2i mousePos);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
