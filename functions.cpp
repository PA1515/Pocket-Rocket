#include "includes.h"
#include "rStrings.h"
#include "functions.h"
#include "CustomChoices.h"

const std::string dead_spaces = std::string(200, ' ');

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

void printChoices(std::vector<CustomChoices>& choicesVec)
{
	uint startingnum = 0;
	std::cout << "Commands:\n";
	for (CustomChoices choice : choicesVec)
	{
		std::cout << choice.getName() << " [" << startingnum << ']' << '\n';
		++startingnum;
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

template <typename T>
bool hasSubstring(T& s1, T& s2, bool wstr)
{
	if (!wtstr)
		return (s1.find(s2) != std::string::npos);
	else
		return (s1.find(s2) != std::wstring::npos);
}

template <typename T>
bool hasSubstringInVector(T& s1, std::vector<T>& s2, bool wstr)
{
	for (T s : s2)
	{
		if (hasSubstring(s1, s, wstr))
			return true;
	}
	return false;
}

std::string directoryEntryToString(std::filesystem::directory_entry entry)
{
	return (std::filesystem::absolute(entry.path()).string());
}

std::string_view directoryEntryToStringView(std::filesystem::directory_entry entry)
{
	std::string strret = std::filesystem::absolute(entry.path()).string();
	std::string_view ret(strret);
	return ret; //doing this to avoid dangling pointers. Convert string to string view.
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

void killProcess(std::string processName)
{
	std::string e = ".exe";
	if (!hasSubstring(processName, e, false))
		processName.append(".exe");
	std::string command = "taskkill /f /im " + processName;
}