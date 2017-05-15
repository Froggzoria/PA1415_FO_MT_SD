#ifndef DESCRIPTION_H
#define DESCRIPTION_H
#include<string>
class Description
{
private:
	std::string name;
	std::string description;

public:
	Description();
	~Description();

	void setName(std::string name);
	void setDescription(std::string description);
	std::string getName();
	std::string getDescription();
};

#endif