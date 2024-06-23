#include <iostream>

long long real_string_hash(std::string s, int p, int n)
{
    long long sum = 0;
    long long hash = 0;
    for (int i = 0; i < s.length(); i++)
    {
        hash += s[i] * pow(p, i);
    }
    hash %= n;
    return hash;
}
int main()
{
    std::string s;
    int p = 0;
    int n = 0;
    std::cout << "Input p: ";
    std::cin >> p;
    std::cout << "Input n: ";
    std::cin >> n;
    while (s != "exit")
    {
        std::cout << "Input string: ";
        std::cin >> s;
        if (s == "exit")
        {
            std::cout << "Hash of string " << "'" << s << "'" << " = " << real_string_hash(s,p,n) << "\n";
            return 0;
        }
        std::cout << "Hash of string " << "'" << s << "'" << " = " << real_string_hash(s, p, n) << "\n";
    }
    return 0;
}