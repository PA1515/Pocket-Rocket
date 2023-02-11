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

#define MAINDO false

std::vector<std::filesystem::directory_entry> dv{};
std::vector<std::string> nL{ ".exe" };
std::vector<std::string> eL{};


int main()
{
	printRocket();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	system("CLS");

	dv = scanForFiles("C:\\Program Files\\", nL, eL, false);
	printVector(dirVecToStringVec(dv));
	
#if MAINDO

	printChoices();
	a = setupChoices();

#endif
	

	waitForExit();
	return 0;
}