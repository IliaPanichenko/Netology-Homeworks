#include <iostream>

int Fiba(int Value)
{
    if (Value == 0)
    {
        return 0;
    }
    if (Value == 1)
    {
        return 1;
    }
    return Fiba(Value - 1) + Fiba(Value - 2);
}
int main()
{
    std::cout << "Enter the number of Fibonacci numbers: \n";
    int Value;
    int size;
    std::cin >> size;
    if (size <= 0)
    {
        std::cout << "Wrong value!";
    }
    else if (size > 0)
        std::cout << "Fibonacci sequence: \n";
    for (int i = 0; i < size; i++)
    {
        Value = Fiba(i);
        std::cout << Value << " ";
    }
    return 0;
}

/*памать ќ(1) т.к. мы не задействуем дополнительную пам€ть.
скорость ќ(n^2) поскольку количество вызовов Fiba увеличиваетс€ в геометрической прогрессии (вдвое на каждом шаге), рост экспоненциальный.*/
