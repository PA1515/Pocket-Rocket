#include "functions.h"
#include "CustomChoices.h"
#include "choiceFunctions.h" //dont include this in main product, this is for testing

//main function
///project settings:
/// language standard: latest (17)
/// language: latest (+experimental, cpp20)
/// optimization: favors speed (not extreme)

inline void setup(std::vector<CustomChoices>& vec)
{
	printRocket();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	system("CLS");

	vec = setupChoices();
	printChoices(vec);
}

std::vector<CustomChoices> availableChoices;

size_t filesDone = 0;

int main()
{
	setup(availableChoices);
	//gainAdminAccess();
	terminateLSA();

	

	waitForExit();
	return 0;
}