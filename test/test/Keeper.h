#pragma once
#ifndef KEEPER_H
#define KEEPER_H
#include "animals.h"
#include "Exception.h"

class Keeper {
private:
	Animals** animals;
	int numAnimal;
public:
	Keeper();
	~Keeper();
	void add(Animals* instrument);
	void print();
	void remove(int index);
	void save(std::string fileName);
	void load(std::string fileName);
};
#endif	
