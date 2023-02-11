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

template <typename T>
bool doesVectorHaveValue(std::vector<T>& vec, T value)
{
	for (T item : vec)
	{
		if (value == item)
			return true;
	}
	return false;
}

bool hasSubstring(std::string s1, std::string s2)
{
	return (s1.find(s2) != std::string::npos);
}

bool hasSubstring(std::string s1, std::vector<std::string>& compare)
{
	for (std::string& value : compare)
	{
		if (s1.find(value) != std::string::npos)
			return true;
	}
	return false;
}

std::string directoryEntryToString(std::filesystem::directory_entry entry)
{
	return (std::filesystem::absolute(entry.path()).string());
}

// this is all probably not the best way of doing this (strings yoink a lot of processing
// time), but it's alright for now.

std::vector<std::filesystem::directory_entry> scanForFiles(std::string path, std::vector<std::string>& includeList, std::vector<std::string>& excludeList, bool fileOnly)
{
	static unsigned long i = 0;
	std::vector<std::filesystem::directory_entry> retVec{};
	for (const auto& directory : std::filesystem::recursive_directory_iterator(path))
	{
		std::string directoryString = directoryEntryToString(directory);
		if (hasSubstring(directoryString, includeList)) //if it has the thing we want
		{
			if (!(hasSubstring(directoryString, excludeList))) //and doesnt have the thing we don't want
			{
				if (fileOnly && directory.is_regular_file())
				{
					retVec.push_back(directory);
				}
				else
				{
					retVec.push_back(directory);
				}
			}
		}
	}
	return retVec;
}

std::vector<std::string> dirVecToStringVec(std::vector<std::filesystem::directory_entry> input)
{
	std::vector<std::string> retVec{};
	for (std::filesystem::directory_entry entry : input)
	{
		retVec.push_back(directoryEntryToString(entry));
	}
	return retVec;
}

void printVector(std::vector<std::string> input)
{
	for (std::string str : input)
	{
		std::cout << str << '\n';
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