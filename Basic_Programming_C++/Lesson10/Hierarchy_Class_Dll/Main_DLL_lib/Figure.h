#pragma once
#include <string>

#ifdef MAINDLLLIB_EXPORTS
#define MAINDLLLIB_API __declspec(dllexport)
#else
#define MAINDLLLIB_API __declspec(dllimport)
#endif

 
class Figure
{
protected:
	std::string name = "Figure";
	bool check = false;
	int number_sides = 0;
	MAINDLLLIB_API virtual bool Check();
public:
	MAINDLLLIB_API std::string get_name();
	MAINDLLLIB_API virtual void print_metod();
	MAINDLLLIB_API void print_enter();
};
