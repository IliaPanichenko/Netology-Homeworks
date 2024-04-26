#include <iostream>
#include "Leaver.h"

int main(int argc, char** argv)
{
	std::string name;
	std::cout << "Input name: ";
	std::cin >> name;
	Leaver Lr;
	std::cout << Lr.leaver(name);
}