#include "fish.h"
#include "animals.h"
#include <string>
Fish::Fish(std::string species, std::string owcolorner, std::string
	foodType)
{
	this->species = species;
	this->color = color;
	this->foodType = foodType;
	std::cout << "Fish default constructor called\n";
}
Fish::Fish(std::string parameters)
{
	this->species = parameters.substr(0, parameters.find(' '));
	parameters.erase(0, parameters.find(' ') + 1);
	this->color = parameters.substr(0, parameters.find(' '));
	parameters.erase(0, parameters.find(' ') + 1);
	this->foodType = parameters.substr(0, parameters.size());
	std::cout << "Fish load-from-file constructor called\n";
}
Fish::~Fish()
{
	std::cout << "Fish default destructor called\n";
}
void Fish::print() {
	std::cout << "Fish instrument: " << "\n";
	std::cout << species << " " << color << " " << foodType << " " << "\n";
}
std::string Fish::getParam() {
	std::string parameters;
	parameters = "Fish" + species + " " + color + " " + foodType;
	return parameters;
}
