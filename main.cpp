#include "functions.h"
#include "CustomChoices.h"

//main function
///project settings:
/// language standard: latest (17)
/// language: latest (+experimental, cpp20)
/// optimization: favors speed (not extreme)

void foo() //arbitrary function for testing reasons
{
	std::cout << "\nfoo\n";
}

std::vector<CustomChoices> a;

int main()
{
	printRocket();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	system("CLS");
	printChoices();
	a = setupChoices();
	waitForExit();
	return 0;
}