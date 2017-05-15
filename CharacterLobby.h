#ifndef CHARACTERLOBBY_H
#define CHARACTERLOBBY_H
#include"CharacterManager.h"
#include"Catalogue.h"
#include<Windows.h>
#include"SFML\Graphics.hpp"
//-----TEMP CONSOLE TESTING-----
#include<iostream>
//-----TEMP CONSOLE TESTING-----

static const int HEAD_AND_DESC = 4;

class CharacterLobby : public sf::Drawable
{
private:
	std::string fntFileName;
	sf::Font fnt0;
	std::string txtFileName;
	sf::Texture bImage;
	sf::Sprite background;
	sf::Text description;
	sf::Text nrOfAttributePoints;
	sf::Text headAndDesc[HEAD_AND_DESC];
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
	bool creationComplete;
	int gameState;
	int currentOption;
	int selectedOption;
	int attributePoints;

	void fontSetup(std::string fntFileName);
	void backgroundSetup(std::string txtFileName);
public:
	CharacterLobby();
	CharacterLobby(std::string fntFileName, std::string txtFileName);
	~CharacterLobby();

	//-----OptionsArea-----//
	//Called first in lobbySetup()
	void setFontForAllText(); //Also sets background texture
	void setHeadAndDesc(int index, std::string header);
	void setHeadAndDescPos(int index, float x, float y);
	void setRaceOptions(int index, std::string raceName);
	void setRaceOptionsPos(int index, float x, float y);
	void setClassOptions(int index, std::string className);
	void setClassOptionsPos(int index, float x, float y);
	void setAttributeOptions(int index, std::string className);
	void setAttributeOptionsPos(int index, float x, float y);
	//---------------------//

	void resetCharacterLobby();
	std::string getRaceName(int index);
	std::string getRaceDescription(int index);
	std::string getClassName(int index);
	std::string getClassDescription(int index);
	/*Select a race for the character in creation 
	TODO: Balance base attributes*/
	void selectRace(int choice);
	/*Select a class for the character in creation 
	TODO: Balance base attributes*/
	void selectClass(int choice);
	int getAttribute(int index);
	void setAttribute(int index, int value);
	/*Function to be called when race, class and attributes have been set.
	The function passes the attribute array and characterID(determined by chosen race) to the
	CharacterManager object that in turn creates and stores the newly created character*/
	void finishCreation(CharacterManager& manager);

	void updateRace(sf::Vector2i mousePos);
	void updateClass(sf::Vector2i mousePos);
	void updateAttribute(sf::Vector2i mousePos);
	int update(sf::Vector2i mousePos, CharacterManager& manager);
	void draw(sf::RenderTarget & target, sf::RenderStates states) const;

};

#endif