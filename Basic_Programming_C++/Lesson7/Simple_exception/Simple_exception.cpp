#include <iostream>
#include <string>
#include <exception>

int function(std::string str, int forbidden_length)
{
    if (forbidden_length == str.length())
    {
        throw std::length_error("Bad length. Good bye!");
    };

    return static_cast<int>(str.length());
};

int main() 
{
    int length;
    int forbidden_length;
    std::string str;
    bool check_length = false;
    try
    {
        do
        {
        std::cout << "Input forbidden length: ";
        std::cin >> forbidden_length;
        if (forbidden_length > 0)
        {
            check_length = true;
        }

        if (forbidden_length <= 0)
        {
            std::cout << "Bad length. Good bye!" << "\n";
            return 0;
        }

        } while (!check_length);
            do
           {
            std::cout << "Input word: ";
            std::cin >> str;

            length = function(str, forbidden_length);

            std::cout << "Word's length \"" << str << "\" = " << length << "\n";

           } while (forbidden_length != length);
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }
    return 0;
}