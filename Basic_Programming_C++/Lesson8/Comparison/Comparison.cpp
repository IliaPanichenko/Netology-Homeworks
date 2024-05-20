#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
//	auto operator <=> (const Fraction&) const = default; For correct work in C++20
	double Dev()
	{
		return (static_cast<double>(numerator_)) / (static_cast<double>(denominator_));
	}
	bool operator == (Fraction right)
	{
		return Dev() == right.Dev();
	};
	bool operator != (Fraction right)
	{
		return !(*this == right);
	};
	bool operator > (Fraction right)
	{
		return Dev() > right.Dev();
	};
	bool operator < (Fraction right)
	{
		return right > *this;
	}
	bool operator >= (Fraction right)
	{
		return !(*this < right);
	};
	bool operator <= (Fraction right)
	{
		return !(*this > right);
	};

};

int main(int argc, char** argv)
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}