#pragma once
#ifndef FISH_H
#define FISH_H
#include "animals.h"
class Fish : public Animals
{
private:
	std::string species;
	std::string color;;
	std::string foodType;
public:
	Fish(std::string species, std::string color,
		std::string foodType);
	explicit Fish(std::string parameters);
	~Fish();
	void print();
	std::string getParam();
};
#endif
