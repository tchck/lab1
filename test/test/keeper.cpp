#include "Keeper.h"
#include "bird.h"
#include "cat.h"
#include "fish.h"
#include <fstream>
#include <string>
Keeper::Keeper()
{
	animals = nullptr;
	numAnimal = 0;
	std::cout << "Keeper default constructor called\n";
}
Keeper::~Keeper()
{
	for (int i = 0; i < numAnimal; i++)
	{
		delete animals[i];
	}
	delete[] animals;
	std::cout << "Keeper default destructor called\n";
}
void Keeper::add(Animals* animal)
{
	Animals** newAnimals = new Animals * [numAnimal + 1];
	for (int i = 0; i < numAnimal; i++)
	{
		newAnimals[i] = animals[i];
	}
	newAnimals[numAnimal] = animal;
	numAnimal++;
	delete[] animals;
	animals = newAnimals;
}
void Keeper::print()
{
	if (numAnimal == 0)
		throw Exception("There are no objects!\n");
	for (int i = 0; i < numAnimal; i++)
	{
		animals[i]->print();
	}
}
void Keeper::remove(int index)
{
	if (index >= numAnimal || index < 0)
		throw Exception("There is no such object!\n");
	Animals** newAnimals = new Animals * [numAnimal - 1];
	int j = 0;
	for (int i = 0; i < numAnimal; i++)
	{
		if (i != index)
		{
			newAnimals[j++] = animals[i];
		}
	}
	delete[] animals;
	animals = newAnimals;
	numAnimal--;
}
void Keeper::save(std::string filename)
{
	std::ofstream file(filename);
	file << numAnimal << std::endl;
	for (int i = 0; i < numAnimal; i++) {
		file << animals[i]->getParam() << "\n";
	}
	file.close();
}
void Keeper::load(std::string filename)
{
	std::ifstream file(filename);
	std::string s;
	while (getline(file, s))
	{
		std::string animal, parameters;
		animal = s.substr(0, s.find(' '));
		s.erase(0, s.find(' ') + 1);
		parameters = s;
		std::cout << parameters << std::endl;
		if (animal == "Bird")
		{
			Bird* str;
			str = new Bird(parameters);
			this->add(str);
		}
		if (animal == "Cat")
		{
			Cat* ca;
			ca = new Cat(parameters);
			this->add(ca);
		}
		if (animal == "Fish")
		{
			Fish* fish;
			fish = new Fish(parameters);
			this->add(fish);
		}
	}
	file.close();
}
