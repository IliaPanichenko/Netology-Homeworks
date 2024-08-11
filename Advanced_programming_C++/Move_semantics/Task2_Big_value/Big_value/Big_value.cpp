#include <iostream>
#include <string>

class big_integer 
{
private:
    std::string value;
public:
    
    big_integer(const std::string& val) : value(val) 
    {
        
        while (value.length() > 1 && value[0] == '0') 
        {
            value.erase(0, 1);
        }
    }

    big_integer(big_integer&& other) : value(std::move(other.value)) {}

    big_integer& operator=(big_integer&& other) 
    {
        if (this != &other) 
        {
            value = std::move(other.value);
        }
        return *this;
    }

    big_integer operator+(const big_integer& other) const 
    {
        std::string result;
        std::string val1 = value;
        std::string val2 = other.value;

        if (val1.length() < val2.length()) 
        {
            val1.insert(0, val2.length() - val1.length(), '0');
        }
        else if (val2.length() < val1.length()) 
        {
            val2.insert(0, val1.length() - val2.length(), '0');
        }

        int carry = 0;
        for (size_t i = 0; i < val1.length(); ++i) 
        {
            int digit1 = val1[val1.length() - i - 1] - '0';
            int digit2 = val2[val2.length() - i - 1] - '0';
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            result.insert(0, 1, static_cast<char>(sum % 10 + '0'));
        }

        if (carry) 
        {
            result.insert(0, 1, '1');
        }

        return big_integer(result);
    }

    big_integer operator*(int num) const 
    {
        if (num == 0) 
        {
            return big_integer("0");
        }

        std::string result;
        int carry = 0;

        for (int i = value.length() - 1; i >= 0 || carry; --i) 
        {
            int digit = (i >= 0) ? value[i] - '0' : 0; 
            int product = digit * num + carry;
            carry = product / 10;
            result.insert(0, 1, static_cast<char>(product % 10 + '0')); 
        }

        if (carry) 
        {
            result.insert(0, 1, static_cast<char>(carry + '0'));
        }

        return big_integer(result);
    }

    friend std::ostream& operator<<(std::ostream& os, const big_integer& num) 
    {
        os << num.value;
        return os;
    }
};

int main() 
{
    big_integer numbers1("000114575");
    big_integer numbers2("78524");
    big_integer result = numbers1 + numbers2;
    std::cout << result << "\n";
    big_integer numbers3("123456789");
    big_integer result2 = numbers3 * 5;
    std::cout << result2 << "\n";
    return 0;
}