#include <iostream>
#define MODE (1)
#ifndef MODE (a)
#error "The MODE not defined"
#endif

int add(int Value1, int Value2)
{
    int Sum = Value1 + Value2;
    return Sum;
}

int main(int argc, char** argv)
{
#if MODE == 0
    std::cout << "Training MODE";
#elif MODE == 1
    int Value1;
    int Value2;
    std::cout << "Working MODE \n";
    std::cout << "Input first value: ";
    std::cin >> Value1;
    std::cout << "Input second value: ";
    std::cin >> Value2;
    std::cout << "Result: " << add(Value1, Value2);
#else 
    std::cout << "Unknown MODE. End of work";
#endif
    return 0;
}