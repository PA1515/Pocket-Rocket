#pragma once
#include "includes.h"

class ScanOptions
{
private:
	std::string_view path;
	std::vector<std::string_view> includes;
	std::vector<std::string_view> excludes;
	bool onlyFile;
public:
	ScanOptions(std::string_view& path, std::vector<std::string_view>& includes, std::vector<std::string_view>& excludes, bool onlyFile);
	std::string_view getPath();
	std::vector<std::string_view> getIncludes();
	std::vector<std::string_view> getExcludes();
	bool isOnlyFile();
};