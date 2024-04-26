#include <iostream>
#include "Greeter.h"

int main(int argc, char** argv)
{
    std::string name;
    std::cout << "Input name: ";
    std::cin >> name;
    Greeter greet;
    std::cout << greet.greeter(name);
    return 0;
}
