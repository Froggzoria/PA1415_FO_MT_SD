#include "SFML\Graphics.hpp"
#include "LevelGenerator.h"
#include <time.h>
#include <iostream>
#include<fstream>
#include<Windows.h>

int main()
{
	srand(static_cast<unsigned>(time(0)));
	std::vector<std::string> keywords;
	keywords.insert(keywords.begin(), "Goofy");
	keywords.insert(keywords.begin(), "Disney");
	keywords.insert(keywords.begin(), "Mickey");
	keywords.insert(keywords.begin(), "Minnie");
	keywords.insert(keywords.begin(), "Gaming");
	keywords.insert(keywords.begin(), "RPG");
	keywords.insert(keywords.begin(), "city");
	keywords.insert(keywords.begin(), "drive");
	keywords.insert(keywords.begin(), "single");
	keywords.insert(keywords.begin(), "pizza");

	LevelGenerator blabla;
	RoomManager * test = blabla.generateWithTwitter(keywords);
	//RoomManager * test = blabla.generateOffline();
	sf::RenderWindow window(sf::VideoMode(1600,960), "TwitterNetHack");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		test->draw(window);
		window.display();
	}
	return 0;
}