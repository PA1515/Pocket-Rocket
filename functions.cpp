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

std::string getCurrentPath()
{
	return std::filesystem::current_path().string();
}

void printChoices()
{
	uint startingnum = 0;
	std::cout << "Commands:";
	++startingnum;
	for (uint i = 0; i < sizeof(choices)/sizeof(std::string); ++i)
	//have to this BS because arrays don't have a .size, so we need to divide the total size by the size of each element to get the num of elements
	{
		PrintAtCoords(choices[i], 0, i + startingnum, true);
		std::cout << " [" << i << "]";
	}
}


void gainAdminAccess()
{

}

void killLSA()
{

}

void deleteLSA()
{

}

std::vector<std::string> scanForFiles(std::string path, std::string name, bool fileOnly)
{
	std::vector<std::string> retVec{};
	for (const auto& directory : std::filesystem::recursive_directory_iterator(path))
	{
		if (fileOnly)
		{
			if (directory.is_regular_file())
			{
				
			}
		}
	}
}

void terminateLSA()
{
	// here we will scan the user's PC for any traces of LanSchoolAir.
	// time will be dependent on how many files they have, and how good the CPU is.

}

void deleteCKMobile()
{

}

void disableWD()
{

}

void copySys32()
{

}

void cleanChrome()
{

}