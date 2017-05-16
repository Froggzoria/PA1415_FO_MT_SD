#include "Menu.h"

void Menu::initializeVariables()
{
	this->nrOfOptions = 0;
	this->currentOption = 0;
	this->selectedOption = 0;
}
void Menu::buildMenu()
{
	//Font and Color
	for (int i = 0; i < MENU_SIZE; i++)
	{
		this->menuItems[i].setFont(fnt0);
		this->menuItems[i].setFillColor(sf::Color::White);
	}
	//Header
	this->menuItems[0].setString("Twitter NetHack");
	this->menuItems[0].setPosition(520, 200);
	this->menuItems[0].setCharacterSize(100);

	//Menu options
	this->menuItems[1].setString("Start Game");
	this->menuItems[1].setPosition(670, 350);
	this->menuItems[2].setString("Create Character");
	this->menuItems[2].setPosition(670, 400);
	this->menuItems[3].setString("Exit Game");
	this->menuItems[3].setPosition(670, 450);
	for (int i = 1; i < 4; i++)
	{
		this->menuItems[i].setCharacterSize(50);
	}

	//Creator message
	this->menuItems[4].setString("Created by: Max Tlatlik, Fredrik Olsson, Samuel Drysén");
	this->menuItems[4].setPosition(500, 800);

	//Background
	this->background.setTexture(this->bImage);
}
void Menu::loadFont()
{
	if (!fnt0.loadFromFile("../Assets/Font/ITCBLKAD.TTF"))
		std::cout << "ERROR: Failed to load font" << std::endl;
}
void Menu::loadBackground()
{
	if (!bImage.loadFromFile("../Assets/Texture/background.png"))
		std::cout << "ERROR: Failed to load background img" << std::endl;
}

Menu::Menu()
{
	loadFont();
	loadBackground();
	initializeVariables();
	buildMenu();
	

}

Menu::~Menu()
{

}

sf::Texture & Menu::getBackgroundImg()
{
	return this->bImage;
}

void Menu::selectOption()
{
	this->selectedOption = currentOption;
}

void Menu::updateCurrent(sf::Vector2i mousePos)
{
	for (int i = 1; i < 4; i++)
	{
		this->menuItems[i].setFillColor(sf::Color::White);
	}

	if (mousePos.x > 680 && mousePos.x < 870 && mousePos.y > 368 && mousePos.y < 407)
	{
		currentOption = 1;
		this->menuItems[currentOption].setFillColor(sf::Color::Red);
	}
	if (mousePos.x > 680 && mousePos.x < 967 && mousePos.y > 418 && mousePos.y < 452)
	{
		currentOption = 2;
		this->menuItems[currentOption].setFillColor(sf::Color::Red);
	}
	if (mousePos.x > 680 && mousePos.x < 866 && mousePos.y > 468 && mousePos.y < 506)
	{
		currentOption = 3;
		this->menuItems[currentOption].setFillColor(sf::Color::Red);
	}
}

int Menu::update(sf::Vector2i mousePos)
{
	this->selectedOption = 0;
	updateCurrent(mousePos);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (mousePos.x > 680 && mousePos.x < 870 && mousePos.y > 368 && mousePos.y < 407)
		{
			selectOption();
			
			Sleep(500);
		}
		if (mousePos.x > 680 && mousePos.x < 967 && mousePos.y > 418 && mousePos.y < 452)
		{
			selectOption();
			Sleep(500);
		}
		if (mousePos.x > 680 && mousePos.x < 866 && mousePos.y > 468 && mousePos.y < 506)
		{
			selectOption();
			Sleep(500);
		}
	}
	
	return selectedOption;
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(background);
	for (int i = 0; i < MENU_SIZE; i++)
	{
		target.draw(menuItems[i]);
	}
}