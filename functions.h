#pragma once
#include "includes.h"
#include "CustomChoices.h"
#include "ScanOptions.h"

const std::string choices[7] = { "Gain administrator access", "Stop LanSchoolAir", "Delete LanSchoolAir", "Delete ContentKeeperMobile",
	"Disable Windows Defender [Registry Method]", "Copy to System32", "Clean Chrome [Remove policies/registries]" };

inline void PrintAtCoords(std::string text, SHORT x, SHORT y, bool clearLine)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	if (clearLine) { std::cout << dead_spaces; }
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	std::cout << text;
}
void printRocket();
void printChoices(std::vector<CustomChoices>& choicesVec);

inline void waitForExit()
{
	while (!GetAsyncKeyState(VK_ESCAPE))
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
}

//helper functions



template <typename T>
bool doesVectorHaveValue(std::vector<T>& vec, T value);

template <typename T>
bool hasSubstring(T& s1, T& s2, bool wstr);
template <typename T>
bool hasSubstringInVector(T& s1, std::vector<T>& s2, bool wstr);

//std::vector<std::filesystem::directory_entry> scanForFiles(std::string path, std::vector<std::string_view>& includeList, std::vector<std::string_view>& excludeList, bool fileOnly, size_t& filesDone);
std::string directoryEntryToString(std::filesystem::directory_entry entry);
std::string_view directoryEntryToStringView(std::filesystem::directory_entry entry);
void printVector(std::vector<std::string> input);
std::vector<std::string> dirVecToStringVec(std::vector<std::filesystem::directory_entry> input);

//scan func
void scanForFiles(ScanOptions& opts, size_t& numScanned, std::vector<std::filesystem::directory_entry>& entries)
{
	for (auto const& dir : std::filesystem::recursive_directory_iterator(opts.getPath()))
	{
		if ((dir.is_regular_file() && opts.isOnlyFile()) || (!opts.isOnlyFile()))
		{

		}
	}
}

void killProcess(std::string processName);