#pragma once
#include <string>

#ifdef MAINDLLLIBDYNAMIC_EXPORTS
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
	 virtual bool MAINDLLLIB_API Check();
public:
	 std::string MAINDLLLIB_API get_name();
	 virtual void MAINDLLLIB_API print_metod();
	 void MAINDLLLIB_API print_enter();
};
