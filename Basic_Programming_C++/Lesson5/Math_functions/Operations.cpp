#include "Math_function.h"
double FunSum(double x, double y)
{
    return x + y;
}
double FunDis(double x, double y)
{
    return x - y;
}
double FunMul(double x, double y)
{
    return x * y;
}
double FunDiv(double x, double y)
{
    return x / y;
}
double FunExp(double x, double y)
{
    double exp;
    exp = 1;
    for (int i = 1; i <= y; i++)
    {
        exp = exp * x;
    }
    return exp;
}