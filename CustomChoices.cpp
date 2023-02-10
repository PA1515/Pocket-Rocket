#include "CustomChoices.h"
#include "functions.h"

CustomChoices::CustomChoices(std::string name, std::string description, std::function<void()> func)
{
	this->name = name; this->description = description; this->func = func;
}

void CustomChoices::runAction()
{
	this->func();
}

std::string CustomChoices::getName()
{
	return this->name;
}

std::string CustomChoices::getDescription()
{
	return this->description;
}

std::vector<CustomChoices> setupChoices()
{
	std::vector<CustomChoices> returnVec{}; //by the way, the [\] symbols are telling the compiler that everything here is one line, so we don't \
	have to concatenate our strings!

	CustomChoices admin("Gain administrator access", "Gains administrator access for the user (input username) if \
the program is in the [system32] directory. Only works at the sign-in screen after a restart, since Windows \
Defender accurately picks up that this program is privelege-escalation.", gainAdminAccess);
	
	CustomChoices stopLanSchoolAir("Stop LanSchoolAir", "Stops all processes connected to the LanSchoolAir app. Please \
do note that LanSchoolAir will probably restart, this is only a temporary solution.", killLSA);

	CustomChoices deleteLanSchoolAir("Delete LanSchoolAir", "Stops all processes and deletes the program files of where \
LanSchoolAir usually is. Please do note that this WILL NOT scan your entire computer for Air, only attempt to clean up \
registries and Program Files.", deleteLSA);

	// add option later to scan entire PC, or at least parts of it. This will take some time (+ ignore Wide Chars, since filesystem
	// doesn't like them....

	CustomChoices deleteContentKeeperMobile("Delete CKMobile (ContentKeeper)", "Deletes the program files and \
registries of ContentKeeperMobile. Please do note that this WILL NOT UNBLOCK WIFI, this will only unblock \
websites LOCALLY on your computer, so you can look anything up at home (or any other non-censored wifi network)",
deleteCKMobile);

	CustomChoices disableWindowsDefender("Disable Windows Defender [Registry Method]", "This disables Windows \
defender, adding a registry key. Please do note that this is not a permanent solution, nor should I provide one; \
Windows Defender is actually pretty good at what it does. You can still exclude this program to prevent it from \
being deleted when Defender scans your PC and finds this :P", disableWD);

	return returnVec;
}