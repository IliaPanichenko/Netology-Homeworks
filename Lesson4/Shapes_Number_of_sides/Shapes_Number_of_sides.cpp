#include <iostream>

class Figure
{
private:
    int sides_count;
    std::string name;
protected:
    Figure (int sides_count, std::string name)
    {
        this->sides_count = sides_count;
        this->name = name;
    }
public:
    Figure() : Figure(0, "Figure") {};

    int get_sides_count()
    {
        return sides_count;
    }

    std::string get_name()
    {
        return name;
    }
};

class Triangle : public Figure
{
public:
    Triangle() : Figure(3, "Triangle") {}
};

class Quadrangle : public Figure
{
public:
    Quadrangle() : Figure(4, "Quadrangle") {}
};

int main()
{
    std::cout << "Number of sides: \n";
    Figure a;
    Triangle tr;
    Quadrangle qd;
    std::cout << a.get_name() << ": " << a.get_sides_count() << "\n";
    std::cout << tr.get_name() << ": " << tr.get_sides_count() << "\n";
    std::cout << qd.get_name() << ": " << qd.get_sides_count() << "\n";

    return 0;
}