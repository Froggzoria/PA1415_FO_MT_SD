#ifndef GAME_H
#define GAME_H
#include"SFML\Graphics.hpp"
#include"CharacterLobby.h"
#include"CharacterManager.h"
#include"ItemManager.h"
#include"RoomManager.h"
#include"Menu.h"
#include"ChatBox.h"

static const int MENU = 0;
static const int GAME = 1;
static const int CHARACTER_CREATION = 2;
static const int EXIT = 3;

class Game
{
private:
	int gameState;
	CharacterLobby lobby;
	CharacterManager manager;
	Catalogue catalogue;
	ItemManager iManager;
	Menu mainMenu;
	RoomManager roomManager;
	ChatBox chatBox;
	
	void testSetup();
public:
	Game();
	~Game();
	
	void update(sf::Vector2i mousePos, bool keyPressed);
	void draw(sf::RenderWindow &window);
};

#endif