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
	returnVec.push_back(admin);

	CustomChoices stopLanSchoolAir("Stop LanSchoolAir", "Stops all processes connected to the LanSchoolAir app. Please \
do note that LanSchoolAir will probably restart, this is only a temporary solution.", killLSA);
	returnVec.push_back(stopLanSchoolAir);

	CustomChoices deleteLanSchoolAir("Delete LanSchoolAir", "Stops all processes and deletes the program files of where \
LanSchoolAir usually is. Please do note that this WILL NOT scan your entire computer for Air, only attempt to clean up \
registries and Program Files.", deleteLSA);
	returnVec.push_back(deleteLanSchoolAir);

	// add option later to scan entire PC, or at least parts of it. This will take some time (+ ignore Wide Chars, since filesystem
	// doesn't like them....

	CustomChoices deleteContentKeeperMobile("Delete CKMobile (ContentKeeper)", "Deletes the program files and \
registries of ContentKeeperMobile. Please do note that this WILL NOT UNBLOCK WIFI, this will only unblock \
websites LOCALLY on your computer, so you can look anything up at home (or any other non-censored wifi network)",
deleteCKMobile);
	returnVec.push_back(deleteContentKeeperMobile);

	CustomChoices disableWindowsDefender("Disable Windows Defender [Registry Method]", "This disables Windows \
defender, adding a registry key. Please do note that this is not a permanent solution, nor should I provide one; \
Windows Defender is actually pretty good at what it does. You can still exclude this program to prevent it from \
being deleted when Defender scans your PC and finds this :P", disableWD);
	returnVec.push_back(disableWindowsDefender);

	CustomChoices copyToSystem32("Copy to System32", "Copies the executable to the [system32] folder. This provides \
easier access to the program through the opening of the Command Prompt, as you can execute it right away (Command \
Prompt is in [system32], so you can launch this program from there easily).", copySys32);
	returnVec.push_back(copyToSystem32);

	CustomChoices clearChrome("Clean Chrome", "Cleans Google Chrome of the annoying 'managed by <organization>', as \
well as deletes a couple of well-known useless/spy extensions, clears policies (so they don't automatically re-install), \
and clears registry (same reason + other tidbits).", cleanChrome);
	returnVec.push_back(clearChrome);

	return returnVec;
}