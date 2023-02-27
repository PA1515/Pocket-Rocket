#include "ScanOptions.h"

ScanOptions::ScanOptions(std::string_view& path, std::vector<std::string_view>& includes, std::vector<std::string_view>& excludes, bool onlyFile)
{
	this->path = path; this->includes = includes; this->excludes = excludes; this->onlyFile = onlyFile;
}

std::string_view ScanOptions::getPath()
{
	return this->path;
}

std::vector<std::string_view> ScanOptions::getIncludes()
{
	return this->includes;
}

std::vector<std::string_view> ScanOptions::getExcludes()
{
	return this->excludes;
}

bool ScanOptions::isOnlyFile()
{
	return this->onlyFile;
}