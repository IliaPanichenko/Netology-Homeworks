#include <iostream>
#include <string>

unsigned long long source_hash_func(const std::string& source)
{
    unsigned long long source_hash = 0;
    for (size_t i = 0; i < source.length(); i++)
    {
        source_hash = (source_hash * 52 + source[i]) % 65713;
    }
    return source_hash;
}

int find_substring_light_rabin_karp(std::string source, std::string substring) 
{
    unsigned long long substring_hash = 0;
    for (int i = 0; i < substring.length(); i++)
    {
        substring_hash = (substring_hash * 52 + source[i]) % 65713;
    }
    for (int i = 0; i <= source.length() - substring.length(); i++)
    {
        if (i > 0) 
        {
            substring_hash = (substring_hash - (unsigned long long)source[i - 1] * (unsigned long long)(pow(52, substring.length() - 1)) % 65713 + 65713) % 65713;
            substring_hash = (substring_hash * 52 + source[i + substring.length() - 1]) % 65713;
        }
        if (substring_hash == source_hash_func(substring))
        {
            bool match = true;
            for (int j = 0; j < substring.length(); j++)
            {
                if (source[i + j] != substring[j]) 
                {
                    match = false;
                    break;
                }
            }
            if (match) 
            {
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    std::string source;
    std::string substring;
    std::cout << "Enter the string for searching: ";
    std::cin >> source;
    while (substring != "exit")
    {
        std::cout << "Enter the substring for searching: ";
        std::cin >> substring;
        if (substring != "exit")
        {
            if (find_substring_light_rabin_karp(source, substring)  == -1)
            {
                std::cout << "Substring " << "'" << substring << "'" << " not found\n";
            }
            else
            {
                std::cout << "Substring " << "'" << substring << "'" <<  " found, index = " << find_substring_light_rabin_karp(source, substring) << "\n";
            }
        }
        else if (substring == "exit" && find_substring_light_rabin_karp(source, substring) > -1)
        {
            std::cout << "Substring " << "'" << substring << "'" << " found, index = " << find_substring_light_rabin_karp(source, substring) << "\n";
        }
        else
        {
            std::cout << "Substring " << "'" << substring << "'" << " not found\n";
            return 0;
        }
    }
    return 0;
}