#include <iostream>

class Calculator
{
public:
    double num1;
    double num2;
    double add(double num1, double num2)
    {
        return num1 + num2;
    }
    
    double multiply(double num1, double num2)
    {
        return num1 * num2;
    }

    double subtract_1_2(double num1, double num2)
    {
        return num1 - num2;
    }

    double subtract_2_1(double num1, double num2)
    {
        return num2 - num1;
    }

    double divide_1_2(double num1, double num2)
    {
        return num1 / num2;
    }

    double divide_2_1(double num1, double num2)
    {
        return num2 / num1;
    }

    bool set_num1(double num1)
    {
        if (num1 == 0) 
            return false;
        this->num1 = num1;
        return true;
    }

    bool set_num2(double num2)
    {
        if (num2 == 0) return false;
        this->num2 = num2;
        return true;
    }
};

int main(int argc, char** argv)
{
    Calculator c;
    c.num1;
    c.num2;
    while (true)
    {
        do
        {
            std::cout << "Input num1: ";
            std::cin >> c.num1;
            if ((c.set_num1(c.num1)) == 0)
            std::cout << "Wrong Value! \n";
        }
            while ((c.set_num1(c.num1)) == 0);
        do
        {
            std::cout << "Input num2: ";
            std::cin >> c.num2;
            if ((c.set_num2(c.num2)) == 0)
            std::cout << "Wrong Value! \n";
        }
            while ((c.set_num2(c.num2)) == 0);
            std::cout << "num1 + num2 = " << c.add(c.num1, c.num2) << "\n";
            std::cout << "num1 * num2 = " << c.multiply(c.num1, c.num2) << "\n";
            std::cout << "num1 - num2 = " << c.subtract_1_2(c.num1, c.num2) << "\n";
            std::cout << "num2 - num1 = " << c.subtract_2_1(c.num1, c.num2) << "\n";
            std::cout << "num1 / num2 = " << c.divide_1_2(c.num1, c.num2) << "\n";
            std::cout << "num2 / num1 = " << c.divide_2_1(c.num1, c.num2) << "\n";      
    }
    return 0;
}