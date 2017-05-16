#include "CharacterLobby.h"

void CharacterLobby::initializeVariables()
{
	this->raceSelected = false;
	this->classSelected = false;
	this->attributesSet = false;
	this->attributePoints = 10;
	
	for (int i = 0; i < ATTRIBUTES; i++)
	{
		this->attributeArr[i] = 0;
	}
}

void CharacterLobby::buildMenu(sf::Font& font, sf::Texture& backgroundImg)
{
	//Font & Size
	this->nrOfAttributePoints.setFont(font);
	this->description.setFont(font);
	for (int i = 0; i < TITLES; i++)
	{
		this->titles[i].setFont(font);
		this->titles[i].setCharacterSize(80);
	}
	for (int i = 0; i < RACES; i++)
	{
		this->raceOptions[i].setFont(font);
	}
	for (int i = 0; i < CLASSES; i++)
	{
		this->classOptions[i].setFont(font);
	}
	for (int i = 0; i < ATTRIBUTES; i++)
	{
		this->attributeOptions[i].setFont(font);
		this->attributePrints[i].setFont(font);
	}
	//Header
	this->titles[0].setString("Choose a Race");
	this->titles[0].setPosition(600, 200);
	this->titles[1].setString("Choose a Class");
	this->titles[1].setPosition(600, 200);
	this->titles[2].setString("Choose your attributes");
	this->titles[2].setPosition(600, 200);

	//Help msg
	this->titles[3].setString("Select - LMB  : Description - RMB");
	this->titles[3].setPosition(300, 850);
	
	//Description
	this->description.setPosition(500, 500);
	this->nrOfAttributePoints.setPosition(300, 650);

	//Menu Options
	for (int i = 0; i < RACES; i++)
	{
		this->raceOptions[i].setString(catalogue.getRaceName(i));
	}
	this->raceOptions[0].setPosition(300, 350);
	this->raceOptions[1].setPosition(300, 400);
	this->raceOptions[2].setPosition(300, 450);
	this->raceOptions[3].setPosition(300, 500);
	this->raceOptions[4].setPosition(300, 550);

	for (int i = 0; i < CLASSES; i++)
	{
		this->classOptions[i].setString(catalogue.getClassName(i));
	}
	this->classOptions[0].setPosition(150, 200);
	this->classOptions[1].setPosition(150, 250);
	this->classOptions[2].setPosition(150, 300);
	this->classOptions[3].setPosition(150, 350);
	this->classOptions[4].setPosition(150, 400);
	this->classOptions[5].setPosition(150, 450);
	this->classOptions[6].setPosition(150, 500);
	this->classOptions[7].setPosition(150, 550);
	this->classOptions[8].setPosition(150, 600);
	this->classOptions[9].setPosition(150, 650);
	this->classOptions[10].setPosition(150, 700);
	this->classOptions[11].setPosition(150, 750);
	this->classOptions[12].setPosition(150, 800);

	for (int i = 0; i < ATTRIBUTES; i++)
	{
		this->attributeOptions[i].setString(catalogue.getAttributeName(i));
	}
    this->attributeOptions[0].setPosition(300, 350);
	this->attributeOptions[1].setPosition(300, 400);
	this->attributeOptions[2].setPosition(300, 450);
	this->attributeOptions[3].setPosition(300, 500);
	this->attributeOptions[4].setPosition(300, 550);
	this->attributeOptions[5].setPosition(300, 600);

	this->attributePrints[0].setPosition(200, 350);
	this->attributePrints[1].setPosition(200, 400);
	this->attributePrints[2].setPosition(200, 450);
	this->attributePrints[3].setPosition(200, 500);
	this->attributePrints[4].setPosition(200, 550);
	this->attributePrints[5].setPosition(200, 600);

	//Background
	this->background.setTexture(backgroundImg);
}

CharacterLobby::CharacterLobby()
{
	/*loadFont();
	loadBackground();
	initializeVariables();
	buildMenu();
	this->catalogue = Catalogue();*/
}

CharacterLobby::CharacterLobby(sf::Font& font, sf::Texture& backgroundImg)
{
	initializeVariables();
	buildMenu(font, backgroundImg);
}

CharacterLobby::~CharacterLobby()
{
	
}

void CharacterLobby::selectRace(int choice)
{
	switch (choice)
	{
	case 0://Dwarf
		this->raceID = 'a';
		this->attributeArr[0] += 5;
		this->attributeArr[1] += 5;
		this->attributeArr[2] += 5;
		this->attributeArr[3] += 5;
		this->attributeArr[4] += 5;
		this->attributeArr[5] += 5;
		break;
	case 1://Elf
		this->raceID = 'b';
		this->attributeArr[0] += 5;
		this->attributeArr[1] += 5;
		this->attributeArr[2] += 5;
		this->attributeArr[3] += 5;
		this->attributeArr[4] += 5;
		this->attributeArr[5] += 5;
		break;
	case 2://Gnome
		this->raceID = 'c';
		this->attributeArr[0] += 5;
		this->attributeArr[1] += 5;
		this->attributeArr[2] += 5;
		this->attributeArr[3] += 5;
		this->attributeArr[4] += 5;
		this->attributeArr[5] += 5;
		break;
	case 3://Human
		this->raceID = 'd';
		this->attributeArr[0] += 5;
		this->attributeArr[1] += 5;
		this->attributeArr[2] += 5;
		this->attributeArr[3] += 5;
		this->attributeArr[4] += 5;
		this->attributeArr[5] += 5;
		break;
	case 4://Orc
		this->raceID = 'e';
		this->attributeArr[0] += 5;
		this->attributeArr[1] += 5;
		this->attributeArr[2] += 5;
		this->attributeArr[3] += 5;
		this->attributeArr[4] += 5;
		this->attributeArr[5] += 5;
		break;
	}
}

void CharacterLobby::selectClass(int choice)
{
	switch (choice)
	{
	case 0://Archeologist
		this->classID = 'a';
		this->attributeArr[0] += 5;
		this->attributeArr[1] += 5;
		this->attributeArr[2] += 5;
		this->attributeArr[3] += 5;
		this->attributeArr[4] += 5;
		this->attributeArr[5] += 5;
		break;
	case 1://Barbarian
		this->classID = 'b';
		this->attributeArr[0] += 5;
		this->attributeArr[1] += 5;
		this->attributeArr[2] += 5;
		this->attributeArr[3] += 5;
		this->attributeArr[4] += 5;
		this->attributeArr[5] += 5;
		break;
	case 2://Caveman
		this->classID = 'c';
		this->attributeArr[0] += 5;
		this->attributeArr[1] += 5;
		this->attributeArr[2] += 5;
		this->attributeArr[3] += 5;
		this->attributeArr[4] += 5;
		this->attributeArr[5] += 5;
		break;
	case 3://Healer
		this->classID = 'd';
		this->attributeArr[0] += 5;
		this->attributeArr[1] += 5;
		this->attributeArr[2] += 5;
		this->attributeArr[3] += 5;
		this->attributeArr[4] += 5;
		this->attributeArr[5] += 5;
		break;
	case 4://Knight
		this->classID = 'e';
		this->attributeArr[0] += 5;
		this->attributeArr[1] += 5;
		this->attributeArr[2] += 5;
		this->attributeArr[3] += 5;
		this->attributeArr[4] += 5;
		this->attributeArr[5] += 5;
		break;
	case 5://Monk
		this->classID = 'f';
		this->attributeArr[0] += 5;
		this->attributeArr[1] += 5;
		this->attributeArr[2] += 5;
		this->attributeArr[3] += 5;
		this->attributeArr[4] += 5;
		this->attributeArr[5] += 5;
		break;
	case 6://Priest
		this->classID = 'g';
		this->attributeArr[0] += 5;
		this->attributeArr[1] += 5;
		this->attributeArr[2] += 5;
		this->attributeArr[3] += 5;
		this->attributeArr[4] += 5;
		this->attributeArr[5] += 5;
		break;
	case 7://Ranger
		this->classID = 'h';
		this->attributeArr[0] += 5;
		this->attributeArr[1] += 5;
		this->attributeArr[2] += 5;
		this->attributeArr[3] += 5;
		this->attributeArr[4] += 5;
		this->attributeArr[5] += 5;
		break;
	case 8://Rogue
		this->classID = 'i';
		this->attributeArr[0] += 5;
		this->attributeArr[1] += 5;
		this->attributeArr[2] += 5;
		this->attributeArr[3] += 5;
		this->attributeArr[4] += 5;
		this->attributeArr[5] += 5;
		break;
	case 9://Samurai
		this->classID = 'j';
		this->attributeArr[0] += 5;
		this->attributeArr[1] += 5;
		this->attributeArr[2] += 5;
		this->attributeArr[3] += 5;
		this->attributeArr[4] += 5;
		this->attributeArr[5] += 5;
		break;
	case 10://Tourist
		this->classID = 'k';
		this->attributeArr[0] += 5;
		this->attributeArr[1] += 5;
		this->attributeArr[2] += 5;
		this->attributeArr[3] += 5;
		this->attributeArr[4] += 5;
		this->attributeArr[5] += 5;
		break;
	case 11://Valkyrie
		this->classID = 'l';
		this->attributeArr[0] += 5;
		this->attributeArr[1] += 5;
		this->attributeArr[2] += 5;
		this->attributeArr[3] += 5;
		this->attributeArr[4] += 5;
		this->attributeArr[5] += 5;
		break;
	case 12://Wizard
		this->classID = 'm';
		this->attributeArr[0] += 5;
		this->attributeArr[1] += 5;
		this->attributeArr[2] += 5;
		this->attributeArr[3] += 5;
		this->attributeArr[4] += 5;
		this->attributeArr[5] += 5;
		break;
	}
}

void CharacterLobby::setAttribute(int index, int value)
{
	this->attributeArr[index] += value;
}

void CharacterLobby::finishCreation(CharacterManager& manager, sf::Texture& itemTexture)
{
	manager.makeCreation(raceID, classID, attributeArr, itemTexture);
}

void CharacterLobby::updateRace(sf::Vector2i mousePos)
{
	for (int i = 0; i < RACES; i++)
	{
		this->raceOptions[i].setFillColor(sf::Color::White);
	}
	if (mousePos.x > 303 && mousePos.x < 419 && mousePos.y > 363 && mousePos.y < 402)
	{
		currentOption = 0;
		this->raceOptions[currentOption].setFillColor(sf::Color::Red);
	}
	if (mousePos.x > 303 && mousePos.x < 366 && mousePos.y > 418 && mousePos.y < 455)
	{
		currentOption = 1;
		this->raceOptions[currentOption].setFillColor(sf::Color::Red);
	}
	if (mousePos.x > 303 && mousePos.x < 417 && mousePos.y > 471 && mousePos.y < 498)
	{
		currentOption = 2;
		this->raceOptions[currentOption].setFillColor(sf::Color::Red);
	}
	if (mousePos.x > 303 && mousePos.x < 431 && mousePos.y > 515 && mousePos.y < 551)
	{
		currentOption = 3;
		this->raceOptions[currentOption].setFillColor(sf::Color::Red);
	}
	if (mousePos.x > 303 && mousePos.x < 369 && mousePos.y > 569 && mousePos.y < 600)
	{
		currentOption = 4;
		this->raceOptions[currentOption].setFillColor(sf::Color::Red);
	}
}

void CharacterLobby::updateClass(sf::Vector2i mousePos)
{
	for (int i = 0; i < CLASSES; i++)
	{
		this->classOptions[i].setFillColor(sf::Color::White);
	}
	if (mousePos.x > 150 && mousePos.x < 360 && mousePos.y > 217 && mousePos.y < 252)
	{
		currentOption = 0;
		this->classOptions[currentOption].setFillColor(sf::Color::Red);
	}
	if (mousePos.x > 150 && mousePos.x < 328 && mousePos.y > 268 && mousePos.y < 302)
	{
		currentOption = 1;
		this->classOptions[currentOption].setFillColor(sf::Color::Red);
	}
	if (mousePos.x > 150 && mousePos.x < 306 && mousePos.y > 317 && mousePos.y < 350)
	{
		currentOption = 2;
		this->classOptions[currentOption].setFillColor(sf::Color::Red);
	}
	if (mousePos.x > 150 && mousePos.x < 270 && mousePos.y > 363 && mousePos.y < 402)
	{
		currentOption = 3;
		this->classOptions[currentOption].setFillColor(sf::Color::Red);
	}
	if (mousePos.x > 150 && mousePos.x < 287 && mousePos.y > 410 && mousePos.y < 455)
	{
		currentOption = 4;
		this->classOptions[currentOption].setFillColor(sf::Color::Red);
	}
	if (mousePos.x > 150 && mousePos.x < 264 && mousePos.y > 461 && mousePos.y < 500)
	{
		currentOption = 5;
		this->classOptions[currentOption].setFillColor(sf::Color::Red);
	}
	if (mousePos.x > 150 && mousePos.x < 255 && mousePos.y > 511 && mousePos.y < 550)
	{
		currentOption = 6;
		this->classOptions[currentOption].setFillColor(sf::Color::Red);
	}
	if (mousePos.x > 150 && mousePos.x < 281 && mousePos.y > 565 && mousePos.y < 608)
	{
		currentOption = 7;
		this->classOptions[currentOption].setFillColor(sf::Color::Red);
	}
	if (mousePos.x > 150 && mousePos.x < 263 && mousePos.y > 615 && mousePos.y < 659)
	{
		currentOption = 8;
		this->classOptions[currentOption].setFillColor(sf::Color::Red);
	}
	if (mousePos.x > 150 && mousePos.x < 299 && mousePos.y > 669 && mousePos.y < 702)
	{
		currentOption = 9;
		this->classOptions[currentOption].setFillColor(sf::Color::Red);
	}
	if (mousePos.x > 150 && mousePos.x < 275 && mousePos.y > 717 && mousePos.y < 750)
	{
		currentOption = 10;
		this->classOptions[currentOption].setFillColor(sf::Color::Red);
	}
	if (mousePos.x > 150 && mousePos.x < 304 && mousePos.y > 764 && mousePos.y < 803)
	{
		currentOption = 11;
		this->classOptions[currentOption].setFillColor(sf::Color::Red);
	}
	if (mousePos.x > 150 && mousePos.x < 296 && mousePos.y > 816 && mousePos.y < 850)
	{
		currentOption = 12;
		this->classOptions[currentOption].setFillColor(sf::Color::Red);
	}
}

void CharacterLobby::updateAttribute(sf::Vector2i mousePos)
{
	for (int i = 0; i < ATTRIBUTES; i++)
	{
		this->attributeOptions[i].setFillColor(sf::Color::White);
	}
	if (mousePos.x > 303 && mousePos.x < 452 && mousePos.y >368 && mousePos.y < 400)
	{
		currentOption = 0;
		this->attributeOptions[currentOption].setFillColor(sf::Color::Red);
	}
	if (mousePos.x > 303 && mousePos.x < 468 && mousePos.y >412 && mousePos.y < 450)
	{
		currentOption = 1;
		this->attributeOptions[currentOption].setFillColor(sf::Color::Red);
	}
	if (mousePos.x > 303 && mousePos.x < 516 && mousePos.y >466 && mousePos.y < 501)
	{
		currentOption = 2;
		this->attributeOptions[currentOption].setFillColor(sf::Color::Red);
	}
	if (mousePos.x > 303 && mousePos.x < 494 && mousePos.y >517 && mousePos.y < 554)
	{
		currentOption = 3;
		this->attributeOptions[currentOption].setFillColor(sf::Color::Red);
	}
	if (mousePos.x > 303 && mousePos.x < 443 && mousePos.y >567 && mousePos.y < 604)
	{
		currentOption = 4;
		this->attributeOptions[currentOption].setFillColor(sf::Color::Red);
	}
	if (mousePos.x > 303 && mousePos.x < 467 && mousePos.y > 617 && mousePos.y < 650)
	{
		currentOption = 5;
		this->attributeOptions[currentOption].setFillColor(sf::Color::Red);
	}
	//Update current attributePoints
	for (int i = 0; i < ATTRIBUTES; i++)
	{
		this->attributePrints[i].setString(std::to_string(attributeArr[i]));
	}

}

int CharacterLobby::update(sf::Vector2i mousePos, CharacterManager& manager, sf::Texture& itemTexture)
{
	this->gameState = 2;

	if (!raceSelected)
	{
		updateRace(mousePos);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			selectedOption = currentOption;
			selectRace(selectedOption);
			raceSelected = true;
			this->description.setString("");
			Sleep(500);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			selectedOption = currentOption;
			this->description.setString(catalogue.getRaceDescription(selectedOption));
			this->description.setPosition(500, 350);
		}
	}
	if (raceSelected && !classSelected)
	{
		updateClass(mousePos);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			selectedOption = currentOption;
			selectClass(selectedOption);
			classSelected = true;
			this->description.setString("");
			Sleep(500);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			selectedOption = currentOption;
			this->description.setString(catalogue.getClassDescription(selectedOption));
			this->description.setPosition(500, 350);
		}
	}
	if (raceSelected && classSelected && !attributesSet)
	{
		this->nrOfAttributePoints.setString("Remaining points: " + std::to_string(attributePoints));
		this->nrOfAttributePoints.setPosition(300, 700);
		updateAttribute(mousePos);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			selectedOption = currentOption;
			setAttribute(selectedOption, 1);
			attributePoints--;
			if (attributePoints == 0)
			{
				attributesSet = true;
				gameState = 0;
				finishCreation(manager, itemTexture);
			}
			this->description.setString("");
			Sleep(500);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			selectedOption = currentOption;
			this->description.setString(catalogue.getAttributeDescription(selectedOption));
			this->description.setPosition(550, 350);
		}
	}
	
	//If character is created and returning to main menu -> reset the lobby
	if (gameState == 0)
	{
		initializeVariables();
	}

	return gameState; //Character Creation = 2, MENU = 0
}

void CharacterLobby::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(background, states);
	target.draw(titles[3], states);
	if (!raceSelected)
	{
		target.draw(titles[0], states);
		for (int i = 0; i < RACES; i++)
		{
			target.draw(raceOptions[i], states);
		}
		target.draw(description);
	}
	if (raceSelected && !classSelected)
	{
		target.draw(titles[1], states);
		for (int i = 0; i < CLASSES; i++)
		{
			target.draw(classOptions[i], states);
		}
		target.draw(description);
	}
	if (raceSelected && classSelected && !attributesSet)
	{
		target.draw(titles[2], states);
		target.draw(nrOfAttributePoints);
		for (int i = 0; i < ATTRIBUTES; i++)
		{
			target.draw(attributeOptions[i], states);
			target.draw(attributePrints[i], states);
		}
		target.draw(description);
	}
}
