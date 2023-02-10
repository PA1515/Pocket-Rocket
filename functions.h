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

//these are all the functions that are used in the commands that the user decides
void gainAdminAccess();
void killLSA();
void deleteLSA();
void deleteCKMobile();
void disableWD();
void copySys32();
void cleanChrome();