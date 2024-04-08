#include <iostream>
#include "Counter.h"
int main(int argc, char** argv)
{
    std::string firstAnswer;
    std::string operand;
    int value;
    std::cout << "Do you want to input first value? Input yes or no :";
    std::cin >> firstAnswer;
    if (firstAnswer == "yes")
    {
        std::cout << "Input first value ";
            std::cin >> value;
            while (operand != "x")
            {
            std::cout << "Input command('+', '-', '=' or 'x') : ";
            std::cin >> operand;
            Counter counter(value);
            counter.metod_count(value, operand);
            }
    }
    else
    {
        std::cout << "Good bye!\n";
    }
    return 0;
}
