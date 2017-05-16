#include"SFML\Graphics.hpp"
#include"Game.h"
#include<iostream>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	sf::RenderWindow gameWindow(sf::VideoMode(1600, 960), "Twitter Nethack");
	gameWindow.setFramerateLimit(60);
	Game game;// = Game();
	sf::Vector2i mousePos;
	bool keyPressed = false;

	while (gameWindow.isOpen())
	{
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			mousePos = sf::Mouse::getPosition(gameWindow);
			switch (event.type)
			{
			case sf::Event::Closed:
				gameWindow.close();
					break;
			case sf::Event::KeyPressed:
				keyPressed = true;
				break;
			case sf::Event::KeyReleased:
				keyPressed = false;
				break;
			}
		}
		game.update(mousePos, keyPressed);
		gameWindow.clear(sf::Color::Black);
		game.draw(gameWindow);
		gameWindow.display();
	}

	return 0;
}