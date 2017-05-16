#include "ChatBox.h"

void ChatBox::loadTexture()
{
	if (!this->windowImg.loadFromFile("../Assets/Texture/Chat_Baloon.png"))
	{
		exit(1);
	}
}

void ChatBox::loadFont()
{
	if (!this->fnt0.loadFromFile("../Assets/Font/cour.ttf"))
	{
		exit(1);
	}
}

void ChatBox::messageWindowSetup()
{
	this->messageWindow.setTexture(this->windowImg);
	this->messageWindow.setPosition(1100, 700);
}

void ChatBox::messageSetup()
{
	for (int i = 0; i < MAX_MESSAGES; i++)
	{
		this->systemMessages[i].setFont(fnt0);
		this->systemMessages[i].setCharacterSize(15);
		this->chatMessages[i].setFont(fnt0);
		this->chatMessages[i].setCharacterSize(15);
	}
	this->systemMessages[0].setString("SYSTEM ERROR: no time left :^(");
	this->systemMessages[0].setPosition(1145, 730);
	this->systemMessages[0].setFillColor(sf::Color::Black);
	
	this->chatMessages[0].setString("Maxtla: Got any sweet l00t?");
	this->chatMessages[0].setPosition(1145, 730);
	this->chatMessages[0].setFillColor(sf::Color::Black);
	this->chatMessages[1].setString("SamDry: Nope, just a short deadline");
	this->chatMessages[1].setPosition(1145, 760);
	this->chatMessages[1].setFillColor(sf::Color::Black);
}

ChatBox::ChatBox()
{
	loadTexture();
	loadFont();
	messageWindowSetup();
	messageSetup();

	this->pressedOnce = false;
	this->showMessageWindow = false;
	this->systemMsg = false;
	this->chatMsg = false;
}

ChatBox::~ChatBox()
{

}

void ChatBox::create()
{

}

void ChatBox::update(sf::Vector2i mousePos, bool keyPressed)
{
	if (keyPressed && !pressedOnce)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			std::cout << "x: " << mousePos.x << " y: " << mousePos.y << std::endl;
			this->showMessageWindow = true;
			this->pressedOnce = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		{
			this->showMessageWindow = false;
			this->pressedOnce = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
		{
			this->systemMsg = true;
			this->chatMsg = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
		{
			this->systemMsg = false;
			this->chatMsg = true;
		}
	}
	if (!keyPressed)
	{
		this->pressedOnce = false;
	}
}

void ChatBox::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if (showMessageWindow)
	{
		target.draw(messageWindow);
		if (systemMsg)
		{
			for (int i = 0; i < MAX_MESSAGES; i++)
			{
				target.draw(this->systemMessages[i]);
			}
		}
		if (chatMsg)
		{
			for (int i = 0; i < MAX_MESSAGES; i++)
			{
				target.draw(this->chatMessages[i]);
			}
		}
	}
}
