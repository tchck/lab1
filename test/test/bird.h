#pragma once
#ifndef BIRD_H
#define BIRD_H
#include "animals.h"
class Bird : public Animals
{
private:
	std::string species;
	std::string color;
	std::string food;
	std::string area;
public:
	Bird(std::string species, std::string color, std::string food,
		std::string area);
	explicit Bird(std::string parameters);
	~Bird();
	void print();
	std::string getParam();
};
#endif
