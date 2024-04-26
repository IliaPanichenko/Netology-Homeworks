#pragma once
#include <string>

#ifdef DYN_LIB_EXPORTS
#define DYN_LIB_API __declspec(dllexport)
#else
#define DYN_LIB_API __declspec(dllimport)
#endif

class Leaver
{
private:
	std::string name;
public:
	DYN_LIB_API std::string leave(std::string name);
};
