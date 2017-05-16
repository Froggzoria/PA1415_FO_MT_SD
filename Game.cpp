#include "Game.h"

void Game::testSetup()
{
	roomManager.addRoom(8, 10, sf::Vector2f(0, 0));
	roomManager.addRoom(12, 19, sf::Vector2f(160, 0));
	roomManager.addRoom(6, 5, sf::Vector2f(0, 320));
	roomManager.addRoom(8, 10, sf::Vector2f(720, 320));
	roomManager.addRoom(10, 10, sf::Vector2f(512, 512));
	roomManager.addRoom(10, 10, sf::Vector2f(800, 160));
	roomManager.addRoom(16, 10, sf::Vector2f(480, 160));
	roomManager.addRoom(10, 10, sf::Vector2f(1200, 64));
	roomManager.addRoom(10, 10, sf::Vector2f(1280, 240));
	roomManager.addRoom(10, 10, sf::Vector2f(1408, 720));
	roomManager.addRoom(10, 10, sf::Vector2f(256, 960 / 2));
	roomManager.addRoom(10, 8, sf::Vector2f(720, 0));
	roomManager.addHalls(roomManager);
	roomManager.addStaircases(roomManager);
}

Game::Game()
{
	this->gameState = 0;
	this->lobby = CharacterLobby(mainMenu.getFont(), mainMenu.getBackgroundImg());
	testSetup();
}

Game::~Game()
{

}

void Game::update(sf::Vector2i mousePos, bool keyPressed)
{
	switch (gameState)
	{
	case MENU:
		gameState = mainMenu.update(mousePos);
		break;
	case GAME:
		manager.update(keyPressed);
		manager.update();
		chatBox.update(mousePos, keyPressed);
		break;
	case CHARACTER_CREATION:
		gameState = lobby.update(mousePos, manager, iManager.getSpriteTexture());
		break;
	case EXIT:
		std::cout << "exit" << std::endl;
		gameState = MENU;
		break;
	}
}

void Game::draw(sf::RenderWindow & window)
{
	switch (gameState)
	{
	case MENU:
		window.draw(mainMenu);
		break;
	case GAME:
		roomManager.draw(window);
		manager.draw(window);
		window.draw(chatBox);
		break;
	case CHARACTER_CREATION:
		window.draw(lobby);
		break;
	case EXIT:

		break;
	}
}