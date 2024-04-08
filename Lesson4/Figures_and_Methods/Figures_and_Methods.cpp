#include <iostream>
#include <string>
class Figure
{
protected:
	std::string name = "Figure";
	bool check = false;
	int number_sides = 0;
	virtual bool Check()
	{
		if (number_sides == 0)
		{ 
			return true; 
		}
		else 
		{ 
			return false; 
		}
	};


public:
	std::string get_name()
	{
		return name;
	}
	virtual void print_metod()
	{
		std::cout << name << ": \n";
		if (Check() == true)
		{
			std::cout << "True \n";
		}
		else
		{
			std::cout << "False \n";
		}
		std::cout << "Numbers of sides: " << number_sides << "\n";
	} 
	void print_enter()
	{
		std::cout << "\n";
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
	bool Check() override
	{
		if (angleA + angleB + angleC == 180)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
public:
	Triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC)
	{
		number_sides = 3;
		name = "Triangle";
		Check();
		this->sideA = sideA;
		this->sideB = sideB;
		this->sideC = sideC;
		this->angleA = angleA;
		this->angleB = angleB;
		this->angleC = angleC;
	}
	void print_metod() override
	{
		Figure::print_metod();
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
	bool Check() override
	{
		if (Triangle :: Check() && angleC == 90)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
	right_triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC) : Triangle(sideA, sideB, sideC, angleA, angleB, angleC)
	{
		Triangle::name = "Right triangle";
	};

};
class isosceles_triangle : public Triangle
{
public:
	bool Check() override
	{
		if (Triangle::Check() && sideA == sideC && angleA == angleC )
		{
			return true;
		}
		else
		{
			return false;
		}
	};
	isosceles_triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC) : Triangle(sideA, sideB, sideC, angleA, angleB, angleC)
	{
		Triangle::name = "Isosceles triangle";
	};

};
class equilateral_triangle : public Triangle
{
public:
	bool Check() override
	{
		if (Triangle::Check() && sideA == sideC && sideC == sideB && angleA == 60 && angleC == 60 && angleB == 60)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
	equilateral_triangle (int sideA, int sideB, int sideC, int angleA, int angleB, int angleC) : Triangle(sideA, sideB, sideC, angleA, angleB, angleC)
	{
		Triangle::name = "Equilateral triangle";
	};

};
class Quadrangle : public Figure
{
protected:

	int sideA = 0;
	int sideB = 0;
	int sideC = 0;
	int sideD = 0;
	int angleA = 0;
	int angleB = 0;
	int angleC = 0;
	int angleD = 0;
	bool Check() override
	{
		if (angleA + angleB + angleC+ angleD == 360)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
public:
	Quadrangle(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD)
	{
		number_sides = 4;
		name = "Quadrangle";
		Check();
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
		Figure::print_metod();
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
	bool Check() override
	{
		if (sideA==sideC && sideB==sideD && Quadrangle::Check() && angleA == 90 && angleB == 90 && angleC == 90 && angleD == 90)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
	Rectangle(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD) : Quadrangle(sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD)
	{
		Quadrangle::name = "Rectangle";
	};

};
class Square : public Quadrangle
{
public:
	bool Check() override
	{
		if (sideA == sideC && sideC == sideB && sideB == sideD && Quadrangle::Check() && angleA == 90 && angleB == 90 && angleC == 90 && angleD == 90)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
	Square(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD) : Quadrangle(sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD)
	{
		Square::name = "Square";
	};

};
class Parallelogram : public Quadrangle
{
public:
	bool Check() override
	{
		if (sideA == sideC && sideB == sideD && Quadrangle::Check() && angleA == angleC && angleB == angleD)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
	Parallelogram(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD) : Quadrangle(sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD)
	{
		Parallelogram::name = "Parallelogram";
	};

};
class Rhombus : public Quadrangle
{
public:
	bool Check() override
	{
		if (sideA == sideC && sideC == sideD && sideB == sideD && Quadrangle::Check() && angleA == angleC && angleB == angleD)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
	Rhombus(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD) : Quadrangle(sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD)
	{
		Rhombus::name = "Rhombus";
	};

};
int main(int argc, char** argv)
{
	Figure figure;
	figure.print_metod();
	figure.print_enter();

	Triangle Triangle(10, 20, 30, 50, 60, 70);
	Figure* Inp_Triangle = &Triangle;
	Inp_Triangle->print_metod();

	right_triangle right_triangle1(10, 20, 30, 50, 60, 90);
	Figure* Inp_RightTriangle = &right_triangle1;
	Inp_RightTriangle->print_metod();

	right_triangle right_triangle2(10, 20, 30, 50, 40, 90);
	Figure* Inp_RightTriangle2 = &right_triangle2;
	Inp_RightTriangle2->print_metod();

	isosceles_triangle isosceles_triangle(10, 20, 10, 50, 60, 50);
	Figure* Inp_IsoTriangle = &isosceles_triangle;
	Inp_IsoTriangle->print_metod();

	equilateral_triangle equilateral_triangle(30, 30, 30, 60, 60, 60);
	Figure* Inp_EquiTriangle = &equilateral_triangle;
	Inp_EquiTriangle->print_metod();

	Quadrangle Quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
	Figure* InpQuadrangle = &Quadrangle;
	InpQuadrangle->print_metod();

	Rectangle Rectangle(10, 20, 10, 20, 90, 90, 90, 90);
	Figure* InpRectangle = &Rectangle;
	InpRectangle->print_metod();

	Square Square(20, 20, 20, 20, 90, 90, 90, 90);
	Figure* InpSquare = &Square;
	InpSquare->print_metod();

	Parallelogram Parallelogram(20, 30, 20, 30, 30, 40, 30, 40);
	Figure* InpParallelogram = &Parallelogram;
	InpParallelogram->print_metod();

	Rhombus Rhombus(30, 30, 30, 30, 30, 40, 30, 40);
	Figure* InpRhombus = &Rhombus;
	InpRhombus->print_metod();
	return 0;
}