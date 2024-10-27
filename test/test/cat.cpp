#include "cat.h"
#include "animals.h"
#include <string>
Cat::Cat(std::string species, std::string color, std::string owner, std::string name)
{
	this->species = species;
	this->color = color;
	this->owner = owner;
	this->name = name;
	std::cout << "Cat default constructor called\n";
}
Cat::Cat(std::string parameters)
{
	this->species = parameters.substr(0, parameters.find(' '));
	parameters.erase(0, parameters.find(' ') + 1);
	this->color = parameters.substr(0, parameters.find(' '));
	parameters.erase(0, parameters.find(' ') + 1);
	this->owner = parameters.substr(0, parameters.find(' '));
	parameters.erase(0, parameters.find(' ') + 1);
	this->name = parameters.substr(0, parameters.find(' '));

	std::cout << "Cat load-from-file constructor called\n";
}
Cat::~Cat()
{
	std::cout << "Cat default destructor called\n";
}
void Cat::print() {
	std::cout << "Cat: " << "\n";
	std::cout << species << " " << color << " " << owner << " " << name << "\n";
}
std::string Cat::getParam() {
	std::string parameters;
	parameters = "Cat " + species + " " + color + " " + owner + " " + name;
	return parameters;
}
