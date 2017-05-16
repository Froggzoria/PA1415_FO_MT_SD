#ifndef CHARACTERLOBBY_H
#define CHARACTERLOBBY_H
#include"SFML\Graphics.hpp"
#include"CharacterManager.h"
#include"Catalogue.h"
#include<Windows.h>
#include<iostream>

static const int TITLES = 4;

class CharacterLobby : public sf::Drawable
{
private:
	sf::Font fnt0;
	sf::Texture bImage;
	sf::Sprite background;
	sf::Text description;
	sf::Text nrOfAttributePoints;
	sf::Text titles[TITLES];
	sf::Text raceOptions[RACES];
	sf::Text classOptions[CLASSES];
	sf::Text attributeOptions[ATTRIBUTES];
	sf::Text attributePrints[ATTRIBUTES];
	
	Catalogue catalogue;
	char classID;
	char raceID;
	int attributeArr[ATTRIBUTES];
	bool raceSelected;
	bool classSelected;
	bool attributesSet;
	int gameState;
	int currentOption;
	int selectedOption;
	int attributePoints;
	
	void initializeVariables();
	void buildMenu();
	void fontSetup();
	void backgroundSetup();
public:
	CharacterLobby();
	~CharacterLobby();

	void selectRace(int choice);
	void selectClass(int choice);
	void setAttribute(int index, int value);
	void finishCreation(CharacterManager& manager, sf::Texture& itemTexture);

	void updateRace(sf::Vector2i mousePos);
	void updateClass(sf::Vector2i mousePos);
	void updateAttribute(sf::Vector2i mousePos);
	int update(sf::Vector2i mousePos, CharacterManager& manager, sf::Texture& itemTexture);
	void draw(sf::RenderTarget & target, sf::RenderStates states) const;

};

#endif