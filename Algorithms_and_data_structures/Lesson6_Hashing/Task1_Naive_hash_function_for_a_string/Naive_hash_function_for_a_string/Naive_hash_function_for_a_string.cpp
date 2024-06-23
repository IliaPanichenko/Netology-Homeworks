#include <iostream>

int simple_string_hash(std::string s)
{
    int hash = 0;
    for (int i = 0; i <= s.length(); i++)
    {
        hash += s[i];
    }
    return hash;
}
int main()
{
    std::string s;
    while (s != "exit")
    {
        std::cout << "Input string: ";
        std::cin >> s;
        if (s == "exit")
        {
            std::cout << "Native hash of string " << "'" << s << "'" << " = " << simple_string_hash(s) << "\n";
            return 0;
        }
        std::cout << "Native hash of string " << "'" << s << "'" << " = " << simple_string_hash(s) << "\n";
    }
    return 0;
}