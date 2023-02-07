#pragma once
#include "includes.h"

class CustomChoices
{
private:
	std::string name, description;
	std::function<void()> func;
public:
	CustomChoices(std::string name, std::string description, std::function<void()> func);
	void runAction();
	std::string getName();
	std::string getDescription();
};

std::vector<CustomChoices> setupChoices(); //return a vector of all custom choices