#include "choiceFunctions.h"
#include "functions.h"

void gainAdminAccess()
{
	system("CLS");

	std::cout << "Please type in your username: ";
	std::string username;
	std::getline(std::cin, username);

	std::cout << '\n';

	std::cout << "Please type in your school/uni's name (type NONE if none): ";
	std::string org;
	std::getline(std::cin, org);
	if (org == "NONE")
	{
		std::cout << "Executing administrator access with username >> " << username << " << and no ORG" << '\n';
		std::string command = "net localgroup Administrators " + username + " /add";
		system(command.c_str());
	} 
	else
	{
		std::cout << "Executing administrator access with username >> " << username << " << and ORG with >> " << org << " <<\n";
		std::string command = "net localgroup Administrators " + org + '\\' + username + " /add";
		system(command.c_str());
	}
}

void killLSA()
{
	std::cout << "Killing processes...\n";
	killProcess("LSAirClient.exe");
	killProcess("LSAirClientService.exe");
	killProcess("LSAirClientUI.exe");
}

void deleteLSA()
{
	system("CLS");
	std::cout << "Killing processes...\n";
	killLSA();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "Deleting folders usually associated with LSA...\n";
	std::filesystem::remove_all("C:\\Program Files (x86)\\LenovoSoftware");
	std::filesystem::remove_all("C:\\ProgramData\\LenovoSoftware");
	std::this_thread::sleep_for(std::chrono::seconds(1));
}


void infiPrint(size_t& t, bool& doPrint)
{
	while (doPrint)
	{
		std::cout << "Files scanned: " << t << '\n';
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}
void terminateLSA()
{
	// here we will scan the user's PC for any traces of LanSchoolAir.
	// time will be dependent on how many files they have, and how good the CPU is.
	system("CLS");
	std::cout << "Terminating LanSchoolAir... (this will take some time)\n";

	size_t filesScanned = 0; bool doPrint = true; //var setup
	std::thread printThread(infiPrint, std::ref(filesScanned), std::ref(doPrint));
	printThread.detach();

	std::string_view path = "C:\\";
	std::vector<std::string_view> scanFor{"lanSchoolAir", "LanSchoolAir", "lanschoolair"};
	std::vector<std::string_view> scanNot{};
	ScanOptions so(path, scanFor, scanNot, false);

	std::vector<std::filesystem::directory_entry> ret{};
	scanForFiles(so, filesScanned, ret);
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