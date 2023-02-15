#pragma once
#include "includes.h"

const std::string choices[7] = { "Gain administrator access", "Stop LanSchoolAir", "Delete LanSchoolAir", "Delete ContentKeeperMobile",
	"Disable Windows Defender [Registry Method]", "Copy to System32", "Clean Chrome [Remove policies/registries]" };

inline void PrintAtCoords(std::string text, SHORT x, SHORT y, bool clearLine);
void printRocket();
void printChoices();

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

bool hasSubstring(std::string& s1, std::string s2);
bool hasSubstring(std::string& s1, std::vector<std::string>& compare);
bool hasSubstring(std::string_view& s1, std::string_view& s2);
bool hasSubstring(std::string_view& s1, std::vector<std::string_view>& compare);
std::vector<std::filesystem::directory_entry> scanForFiles(std::string& path, std::vector<std::string_view>& includeList, std::vector<std::string_view>& excludeList, bool fileOnly, size_t& filesDone);
std::string directoryEntryToString(std::filesystem::directory_entry entry);
std::string_view directoryEntryToStringView(std::filesystem::directory_entry entry);
void printVector(std::vector<std::string> input);
std::vector<std::string> dirVecToStringVec(std::vector<std::filesystem::directory_entry> input);

//these are all the functions that are used in the commands that the user decides
void gainAdminAccess();
void killLSA();
void deleteLSA();
void terminateLSA();
void deleteCKMobile();
void disableWD();
void copySys32();
void cleanChrome();