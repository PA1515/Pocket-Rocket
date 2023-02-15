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

bool hasSubstring(std::string& s1, std::string& s2)
{
	return (s1.find(s2) != std::string::npos);
}

bool hasSubstring(std::string& s1, std::vector<std::string>& compare)
{
	for (std::string& value : compare)
	{
		if (s1.find(value) != std::string::npos)
			return true;
	}
	return false;
}
//overloads for string_view since it takes less memory to process
bool hasSubstring(std::string_view& s1, std::string_view& s2)
{
	return (s1.find(s2) != std::string::npos);
}
bool hasSubstring(std::string_view& s1, std::vector<std::string_view>& compare)
{
	for (std::string_view& value : compare)
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

std::string_view directoryEntryToStringView(std::filesystem::directory_entry entry)
{
	std::string strret = std::filesystem::absolute(entry.path()).string();
	std::string_view ret(strret);
	return ret; //doing this to avoid dangling pointers. Convert string to string view.
}

// this is all probably not the best way of doing this (strings yoink a lot of processing
// time), but it's alright for now.

std::vector<std::filesystem::directory_entry> scanForFiles(std::string& path, std::vector<std::string_view>& includeList, std::vector<std::string_view>& excludeList, bool fileOnly, size_t& filesDone)
{
	// doing the classic "recursive_directory_operator" won't help here, since
	// it causes a stack buffer overflow (function gets too large)
	// we'll have to break it down into smaller pieces, essentially doing
	// the recursive part manually... Well, shit.
	// that's fine. We can just find the folders that shit will probably appear in, and
	// go from there.
	// make it an argument.

	// nah, fuck it. we use ChatGPT for answers to our questions.
	// it came up with using dynamic memory allocation, so IG we're doing that now...
	// yahoo

	std::vector<std::filesystem::directory_entry> retVec{};

	std::vector<std::filesystem::path*> path_vec;
	path_vec.push_back(new std::filesystem::path(path));

	filesDone = 0;
	while (!path_vec.empty())
	{
		//get current path on the chopping block
		std::filesystem::path* current_path = path_vec.front();

		//remove it from the vector (so we don't use it again)
		path_vec.erase(path_vec.begin());
		
		//loop over things in directory
		for (const auto& entry : std::filesystem::directory_iterator(*current_path))
		{
			auto str = directoryEntryToStringView(entry); //string_view for operations
			if (hasSubstring(str, includeList) && !hasSubstring(str, excludeList)) //check for includes/excludes
			{
				if (entry.is_directory())
				{
					if (!fileOnly)
					{
						retVec.push_back(entry);
					}
					std::filesystem::path* new_path = new std::filesystem::path(entry.path());
					path_vec.push_back(new_path);
				}
				else
				{
					retVec.push_back(entry);
				}
				++filesDone;
			}
		}
		delete current_path; //no memory leaks please!!! :)))
	}


	return retVec;
	// we will return a vector of all found directory entries that coincide with the dirs/files
	// we want to find.
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