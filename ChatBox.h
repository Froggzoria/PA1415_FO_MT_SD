#ifndef CHATBOX_H
#define CHATBOX_H
#include"SFML\Network.hpp"
#include"SFML\Graphics.hpp"
#include<iostream>

static const int MAX_MESSAGES = 5;
/*
how to use?
*/


class ChatBox : public sf::Drawable
{
private:
	sf::UdpSocket socket;
	sf::IpAddress foo;

	sf::Texture windowImg;
	sf::Font fnt0;
	sf::Text systemMessages[MAX_MESSAGES];
	sf::Text chatMessages[MAX_MESSAGES];
	sf::Sprite messageWindow;

	bool pressedOnce;
	bool showMessageWindow;
	bool systemMsg;
	bool chatMsg;

	void loadTexture();
	void loadFont();
	void messageWindowSetup();
	void messageSetup();
public:
	ChatBox();
	~ChatBox();

	void create();
	/*bool roomEnteredMsg();
	bool doorClosedMsg();
	void intimidationMsg();
	void playerWonMsg();
	void playerLostMsg();
	void fleeFailedMsg();
	void fleeSuccededMsg();
	void showPlayerMsg(std::string theMsg);
	void showEntReply(std::string theReply);
	void itemAddedMsg(Item item);
	void failedToPickUpMsg();*/

	void update(sf::Vector2i mousePos, bool keyPressed);
	// Inherited via Drawable
	void draw(sf::RenderTarget & target, sf::RenderStates states) const;

};

#endif