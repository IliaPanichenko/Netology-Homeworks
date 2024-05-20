#pragma once
#include <string>
class Counter
{
private:
    int value;
public:
    Counter(int value);
    int metod_count(int& value, std::string operand);
};