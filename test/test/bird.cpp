#include "bird.h"
#include "animals.h"
#include <string>
Bird::Bird(std::string species, std::string color, std::string
	food, std::string area)
{
	this->species = species;
	this->color = color;
	this->food = food;
	this->area = area;
	std::cout << "Bird default constructor called\n";
}
Bird::Bird(std::string parameters)
{
	this->species = parameters.substr(0, parameters.find(' '));
	parameters.erase(0, parameters.find(' ') + 1);
	this->color = parameters.substr(0, parameters.find(' '));
	parameters.erase(0, parameters.find(' ') + 1);
	this->food = parameters.substr(0, parameters.find(' '));
	parameters.erase(0, parameters.find(' ') + 1);
	this->area = parameters.substr(0, parameters.size());
	std::cout << "Bird load-from-file constructor called\n";
}
Bird::~Bird()
{
	std::cout << "Bird default destructor called\n";
}
void Bird::print() {
	std::cout << "Bird: " << "\n";
	std::cout << species << " " << color << " " <<
		food << " " << area << " " << "\n";
}
std::string Bird::getParam() {
	std::string parameters;
	parameters = "Bird " + species + " " + color + " " + food + " " + area;
	return parameters;
}
