#include "CharacterLobby.h"

void CharacterLobby::fontSetup(std::string fntFileName)
{
	this->fntFileName = fntFileName;
	if (!fnt0.loadFromFile(this->fntFileName))
		std::cout << "ERROR: Failed to load font" << std::endl;
}

void CharacterLobby::backgroundSetup(std::string txtFileName)
{
	this->txtFileName = txtFileName;
	if (!bImage.loadFromFile(this->txtFileName))
		std::cout << "ERROR: Failed to load font" << std::endl;
}

CharacterLobby::CharacterLobby()
{
	this->raceSelected = false;
	this->classSelected = false;
	this->attributesSet = false;
	this->catalogue = Catalogue();
	for (int i = 0; i < ATTRIBUTES; i++)
	{
		this->attributeArr[i] = 0;
	}
}

CharacterLobby::CharacterLobby(std::string fntFileName, std::string txtFileName)
{
	fontSetup(fntFileName);
	backgroundSetup(txtFileName);
	this->raceSelected = false;
	this->classSelected = false;
	this->attributesSet = false;
	this->gameState = 2;
	this->attributePoints = 10;
	this->catalogue = Catalogue();
	for (int i = 0; i < ATTRIBUTES; i++)
	{
		this->attributeArr[i] = 0;
	}
	
}

CharacterLobby::~CharacterLobby()
{
	
}

void CharacterLobby::setFontForAllText()
{
	this->background.setTexture(bImage);
	this->description.setFont(this->fnt0);
	this->nrOfAttributePoints.setFont(this->fnt0);
	for (int i = 0; i < HEAD_AND_DESC; i++)
	{
		this->headAndDesc[i].setFont(this->fnt0);
	}
	for (int i = 0; i < RACES; i++)
	{
		this->raceOptions[i].setFont(this->fnt0);
	}
	for (int i = 0; i < CLASSES; i++)
	{
		this->classOptions[i].setFont(this->fnt0);
	}
	for (int i = 0; i < ATTRIBUTES; i++)
	{
		this->attributeOptions[i].setFont(this->fnt0);
	}
	for (int i = 0; i < ATTRIBUTES; i++)
	{
		this->attributePrints[i].setFont(this->fnt0);
	}
}

void CharacterLobby::setHeadAndDesc(int index, std::string header)
{
	this->headAndDesc[index].setString(header);
	this->headAndDesc[index].setCharacterSize(80);
	this->headAndDesc[index].setFillColor(sf::Color::White);
}

void CharacterLobby::setHeadAndDescPos(int index, float x, float y)
{
	this->headAndDesc[index].setPosition(x, y);
}

void CharacterLobby::setRaceOptions(int index, std::string raceName)
{
	this->raceOptions[index].setString(raceName);
	this->raceOptions[index].setCharacterSize(50);
	this->raceOptions[index].setFillColor(sf::Color::White);
}

void CharacterLobby::setRaceOptionsPos(int index, float x, float y)
{
	this->raceOptions[index].setPosition(x, y);
}

void CharacterLobby::setClassOptions(int index, std::string className)
{
	this->classOptions[index].setString(className);
	this->classOptions[index].setCharacterSize(50);
	this->classOptions[index].setFillColor(sf::Color::White);
}

void CharacterLobby::setClassOptionsPos(int index, float x, float y)
{
	this->classOptions[index].setPosition(x, y);
}

void CharacterLobby::setAttributeOptions(int index, std::string className)
{
	this->attributeOptions[index].setString(className);
	this->attributeOptions[index].setCharacterSize(50);
	this->attributeOptions[index].setFillColor(sf::Color::White);
}

void CharacterLobby::setAttributeOptionsPos(int index, float x, float y)
{
	this->attributeOptions[index].setPosition(x, y);
	this->attributePrints[index].setPosition((x - 100), y);
}

void CharacterLobby::resetCharacterLobby()
{
	for (int i = 0; i < ATTRIBUTES; i++)
	{
		this->attributeArr[i] = 0;
	}
	this->attributePoints = 10;
	this->raceSelected = false;
	this->classSelected = false;
	this->attributesSet = false;
}

std::string CharacterLobby::getRaceName(int index)
{
	return catalogue.getRaceName(index);
}

std::string CharacterLobby::getRaceDescription(int index)
{
	return catalogue.getRaceDescription(index);
}

std::string CharacterLobby::getClassName(int index)
{
	return catalogue.getClassName(index);
}

std::string CharacterLobby::getClassDescription(int index)
{
	return catalogue.getClassDescription(index);
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

int CharacterLobby::getAttribute(int index)
{
	return this->attributeArr[index];
}

void CharacterLobby::setAttribute(int index, int value)
{
	this->attributeArr[index] += value;
}

void CharacterLobby::finishCreation(CharacterManager& manager)
{
	manager.makeCreation(raceID, classID, attributeArr);
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

int CharacterLobby::update(sf::Vector2i mousePos)
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
		resetCharacterLobby();
	}

	return gameState; //Character Creation = 2, MENU = 0
}

void CharacterLobby::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(background, states);
	target.draw(headAndDesc[3], states);
	if (!raceSelected)
	{
		target.draw(headAndDesc[0], states);
		for (int i = 0; i < RACES; i++)
		{
			target.draw(raceOptions[i], states);
		}
		target.draw(description);
	}
	if (raceSelected && !classSelected)
	{
		target.draw(headAndDesc[1], states);
		for (int i = 0; i < CLASSES; i++)
		{
			target.draw(classOptions[i], states);
		}
		target.draw(description);
	}
	if (raceSelected && classSelected && !attributesSet)
	{
		target.draw(headAndDesc[2], states);
		target.draw(nrOfAttributePoints);
		for (int i = 0; i < ATTRIBUTES; i++)
		{
			target.draw(attributeOptions[i], states);
			target.draw(attributePrints[i], states);
		}
		target.draw(description);
	}
}
