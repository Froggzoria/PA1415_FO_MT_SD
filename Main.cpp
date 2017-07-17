#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "RoomManager.h"
#include <time.h>

int main()
{
	srand(static_cast<unsigned>(time(0)));
	sf::RenderWindow window(sf::VideoMode(1600,960), "TwitterNetHack");

	RoomManager test;
	test.addRoom(8, 10, sf::Vector2f(0, 0));
	test.addRoom(12, 19, sf::Vector2f(160, 0));
	test.addRoom(6, 5, sf::Vector2f(0, 320));
	test.addRoom(8, 10, sf::Vector2f(720, 320));
	test.addRoom(10, 10, sf::Vector2f(512, 512));
	test.addRoom(10, 10, sf::Vector2f(800, 160));
	test.addRoom(16, 10, sf::Vector2f(480, 160));
	test.addRoom(10, 10, sf::Vector2f(1200, 64));
	test.addRoom(10, 10, sf::Vector2f(1280, 240));
	test.addRoom(10, 10, sf::Vector2f(1408, 720));
	test.addRoom(10, 10, sf::Vector2f(256, 960/2));
	test.addRoom(10, 8, sf::Vector2f(720, 0));
	test.addHalls(test);
	test.addStaircases(test);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		test.draw(window);
		window.display();
	}
	return 0;
}