#include "CustomChoices.h"

CustomChoices::CustomChoices(std::string name, std::string description, std::function<void()> func)
{
	this->name = name; this->description = description; this->func = func;
}

void CustomChoices::runAction()
{
	this->func();
}

std::string CustomChoices::getName()
{
	return this->name;
}

std::string CustomChoices::getDescription()
{
	return this->description;
}

void gainAdminAccess()
{

}

std::vector<CustomChoices> setupChoices()
{
	std::vector<CustomChoices> returnVec{}; //by the way, the [\] symbols are telling the compiler that everything here is one line, so we don't \
	have to concatenate our strings!

	CustomChoices admin("Gain administrator access", "Gains administrator access for the user (input username) if \
the program is in the [system32] directory. Only works at the sign-in screen after a restart, since Windows \
Defender accurately picks up that this program is privelege-escalation.", gainAdminAccess);
	
	CustomChoices 

	return returnVec;
}