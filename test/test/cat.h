#pragma once
#ifndef CAT_H
#define CAT_H
#include "animals.h"
class Cat : public Animals
{
private:
	std::string species;
	std::string color;
	std::string owner;
	std::string name;
public:
	Cat(std::string species, std::string color, std::string owner, std::string name);
	explicit  Cat(std::string parameters);
	~Cat();
	void print();
	std::string getParam();
};
#endif
