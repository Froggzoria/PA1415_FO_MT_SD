#include "Description.h"

Description::Description()
{
	this->name = "Unknown";
	this->description = "Unknown";
}

Description::~Description()
{

}

void Description::setName(std::string name)
{
	this->name = name;
}

void Description::setDescription(std::string description)
{
	this->description = description;
}

std::string Description::getName()
{
	return this->name;
}

std::string Description::getDescription()
{
	return this->description;
}
