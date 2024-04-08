#include <iostream>
#include "Math_function.h"
int main (int argc, char** argv)
{
    double FirstValue;
    double SecondValue;
    double Operation;
    while (true)
    {
        std::cout << "Input first value: ";
        std::cin >> FirstValue;
        std::cout << "Input second value: ";
        std::cin >> SecondValue;
        std::cout << "Select operation: ";
        std::cin >> Operation;
        if (Operation == 1 || Operation == 2 || Operation == 3 || Operation == 4 || Operation == 5)
        {
            if (Operation == 1)
            {
                std::cout << "Sum " << FirstValue << " + " << SecondValue << " = " << FunSum(FirstValue, SecondValue) << "\n";
            }
            if (Operation == 2)
            {
                std::cout << "Subtraction " << FirstValue << " - " << SecondValue << " = " << FunDis(FirstValue, SecondValue) << "\n";
            }
            if (Operation == 3)
            {
                std::cout << "Multiplication " << FirstValue << " * " << SecondValue << " = " << FunMul(FirstValue, SecondValue) << "\n";
            }
            if (Operation == 4)
            {
                std::cout << "Division " << FirstValue << " / " << SecondValue << " = " << FunDiv(FirstValue, SecondValue) << "\n";
            }
            if (Operation == 5)
            {
                std::cout << "Exponentiation " << FirstValue << " exp " << SecondValue << " = " << FunExp(FirstValue, SecondValue) << "\n";
            }
        }
        else 
        {
            std::cout << "Wrong operation! \n";
        }

    }
    return 0;
}