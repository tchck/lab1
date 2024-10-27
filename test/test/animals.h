#pragma once
#ifndef ANIMALS_H
#define ANIMALS_H
#include <iostream>
class Animals
{
public:
	Animals() { std::cout << "Animals default constructor called" << std::endl; }
	virtual ~Animals() { std::cout << "Animals destructor called" << std::endl; }
	virtual void print() = 0;
	virtual std::string getParam() = 0;
};
#endif
