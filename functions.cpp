#include "includes.h"
#include "rStrings.h"
#include "functions.h"

const std::string dead_spaces = std::string(200, ' ');
inline void PrintAtCoords(std::string text, SHORT x, SHORT y, bool clearLine)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	if (clearLine) { std::cout << dead_spaces; }
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	std::cout << text;
}

typedef unsigned int uint;
typedef unsigned long ulong;

void printRocket()
{
	uint num = 0;
	for (std::string line : rocketStrings)
	{
		PrintAtCoords(line, 0, num, true);
		++num;
	}
	++num;
	PrintAtCoords("Art by Donovan Bake", 0, num, true);
	++num;
	for (std::string line : pocketStrings)
	{
		PrintAtCoords(line, 0, num, true);
		++num;
	}
}