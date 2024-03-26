#include <iostream>

class Counter
{
private:
    int Value;
public:
    Counter()
    {
        Value = 1;
    }
    Counter(int &Value)
    {
        Value = Value;
    }
    int UpValue(int &Value)
    {
        Value++;
        return Value;
    }
    int DownValue(int &Value)
    {
        Value--;
        return Value;
    }
    void PrintValue(int& Value)
    {
        std::cout << Value << "\n";
    }
};

int main(int argc, char** argv)
{
    Counter Count;
    int DefaultValue;
    std::string Answer;
    std::string Symbol;
    Counter DefaultCounter();
    std::cout << "Do you want to specify the initial value of the counter? Enter yes or no: ";
    std::cin >> Answer;
    if (Answer == "yes")
    {
            std::cout << "Enter the initial counter value: ";
            std::cin >> DefaultValue;
            do {
            Counter NewCounter(int DefaultValue);
            std::cout << "Enter the command ('+', '-', '=' or 'x'): ";
            std::cin >> Symbol;
            if (Symbol == "-")
            {
                Count.DownValue(DefaultValue);
            }
            if (Symbol == "+")
            {
                Count.UpValue(DefaultValue);
            }
            if (Symbol == "=")
            {
                Count.PrintValue(DefaultValue);
            }
            if (Symbol == "x")
            {
                std::cout << "Good bye!";
            }
        } while (Symbol != "x");
    }
    else
    {
        std::cout << "Good bye!";
    };
    return 0;
}
