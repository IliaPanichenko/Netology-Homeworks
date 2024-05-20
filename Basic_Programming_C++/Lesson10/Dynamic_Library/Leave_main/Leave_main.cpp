#include <iostream>
#include "Leaver.h"

int main()
{
    std::string name;
    std::cout << "Input name: ";
    std::cin >> name;
    Leaver leave;
    std::cout << leave.leave(name);
}
