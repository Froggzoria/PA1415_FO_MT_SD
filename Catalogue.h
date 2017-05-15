#ifndef CATALOGUE_H
#define CATALOGUE_H
#include<string>
#include"Description.h"

static const int RACES = 5;
static const int CLASSES = 13;
static const int ATTRIBUTES = 6;

class Catalogue
{
private:
	Description pRace[RACES];
	Description pClass[CLASSES];
	Description pAttributes[ATTRIBUTES];

public:
	Catalogue();
	~Catalogue();

	/*Returns the name of the race at index*/
	std::string getRaceName(int index);

	/*Returns the description of the race at index*/
	std::string getRaceDescription(int index);

	/*Returns the name of the class at index*/
	std::string getClassName(int index);

	/*Returns the description of the class at index*/
	std::string getClassDescription(int index);

	std::string getAttributeName(int index);

	std::string getAttributeDescription(int index);
};

#endif