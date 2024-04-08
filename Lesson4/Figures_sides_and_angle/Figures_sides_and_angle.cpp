#include <iostream>
#include <string>
class Figure
{
protected:
	std::string name;
public:
	std::string get_name()
	{
		return name;
	}
	virtual void print_metod()
	{
		std::cout << name;
	}
};
class Triangle : public Figure
{
protected:
	int sideA = 0;
	int sideB = 0;
	int sideC = 0;
	int angleA = 0;
	int angleB = 0;
	int angleC = 0;
public:
	Triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC)
	{
		name = "Triangle";
		this->sideA = sideA;
		this->sideB = sideB;
		this->sideC = sideC;
		this->angleA = angleA;
		this->angleB = angleB;
		this->angleC = angleC;
	}
	   void print_metod() override
	   {
		   std::cout << name << ":" << "\n";
		   std::cout << "Sides: ";
		   std::cout << "a = " << sideA << ", b = " << sideB << ", c = " << sideC << "\n";
		   std::cout << "Angles: ";
		   std::cout << "A = " << angleA << ", B = " << angleB << ", C = " << angleC << "\n";
		   std::cout << "\n";
	   }
};
class right_triangle : public Triangle
{ 
public:
	right_triangle(int sideA, int sideB, int sideC, int angleA, int angleB) : Triangle(sideA, sideB, sideC, angleA, angleB, 90)
	{
		Triangle::name = "Right triangle";
	};

};
class isosceles_triangle : public Triangle
{
public:
	isosceles_triangle(int sideA, int sideB,int angleA, int angleB) : Triangle(sideA, sideB, sideA, angleA, angleB, angleA)
	{
		Triangle::name = "Isosceles triangle";
	};

};
class equilateral_triangle : public Triangle
{
public:
	equilateral_triangle(int sideA, int angleA) : Triangle(sideA, sideA, sideA, angleA, angleA, angleA)
	{
		Triangle::name = "Equilateral triangle";
	};

};
class Quadrangle : public Figure
{
protected:
    int sideA=0;
    int sideB=0;
    int sideC=0;
    int sideD=0;
    int angleA=0;
    int angleB=0;
    int angleC=0;
    int angleD=0;
public:
    Quadrangle(int sideA, int sideB, int sideC,int sideD, int angleA, int angleB, int angleC, int angleD)
	{
		name = "Quadrangle";
		this->sideA = sideA;
		this->sideB = sideB;
		this->sideC = sideC;
		this->sideD = sideD;
		this->angleA = angleA;
		this->angleB = angleB;
		this->angleC = angleC;
		this->angleD = angleD;
	}

	void print_metod() override
	{
		std::cout << name << ":" << "\n";
		std::cout << "Sides: ";
		std::cout << "a = " << sideA << ", b = " << sideB << ", c = " << sideC << ", d = " << sideD << "\n";
		std::cout << "Angles: ";
		std::cout << "A = " << angleA << ", B = " << angleB << ", C = " << angleC << ", D = " << angleD << "\n";
		std::cout << "\n";
	}
};
class Rectangle : public Quadrangle
{
public:
	Rectangle(int sideA, int sideB, int angleA) : Quadrangle(sideA, sideB, sideA, sideB, angleA, angleA, angleA, angleA)
	{
		Quadrangle::name = "Rectangle";
	};

};
class Square : public Quadrangle
{
public:
	Square(int sideA, int angleA) : Quadrangle(sideA, sideA, sideA, sideA, angleA, angleA, angleA, angleA)
	{
		Square::name = "Square";
	};

};
class Parallelogram : public Quadrangle
{
public:
	Parallelogram(int sideA, int sideB, int angleA, int angleB) : Quadrangle(sideA, sideB, sideA, sideB, angleA, angleB, angleA, angleB)
	{
		Parallelogram::name = "Parallelogram";
	};

};
class Rhombus : public Quadrangle
{
public:
	Rhombus(int sideA, int angleA, int angleB) : Quadrangle(sideA, sideA, sideA, sideA, angleA, angleB, angleA, angleB)
	{
		Rhombus::name = "Rhombus";
	};

};
int main(int argc, char** argv)
{
	Triangle Triangle(10, 20, 30, 50, 60, 70);
	Figure* Inp_Triangle = &Triangle;
	Inp_Triangle->print_metod();

	right_triangle right_triangle(10, 20, 30, 50, 60);
	Figure* Inp_RightTriangle = &right_triangle;
	Inp_RightTriangle->print_metod();

	isosceles_triangle isosceles_triangle(10, 20, 50, 60);
	Figure* Inp_IsoTriangle = &isosceles_triangle;
	Inp_IsoTriangle->print_metod();

	equilateral_triangle equilateral_triangle(30, 60);
	Figure* Inp_EquiTriangle = &equilateral_triangle;
	Inp_EquiTriangle->print_metod();

	Quadrangle Quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
	Figure* InpQuadrangle = &Quadrangle;
	InpQuadrangle->print_metod();

	Rectangle Rectangle(10, 20, 90);
	Figure* InpRectangle = &Rectangle;
	InpRectangle->print_metod();

	Square Square(20, 90);
	Figure* InpSquare = &Square;
	InpSquare->print_metod();

	Parallelogram Parallelogram(20, 30, 30, 40);
	Figure* InpParallelogram = &Parallelogram;
	InpParallelogram->print_metod();

	Rhombus Rhombus(30, 30, 40);
	Figure* InpRhombus = &Rhombus;
	InpRhombus->print_metod();
	return 0;
}