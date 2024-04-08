#include "Counter.h"
#include <iostream>

Counter::Counter(int value)
{
    this->value = value;
};
int Counter :: metod_count(int& value, std::string operand)
{
    if (operand == "+")
    {
        value ++;
        return value;
    }
    if (operand == "-")
    {
        value --;
        return value;
    }
    if (operand == "=")
    {
        std::cout << value << "\n";
        return value;
    }
    if (operand == "x")
    {
        std::cout << value << "\n";
        std::cout << "Good bye!";
        return 0;
    }
};
