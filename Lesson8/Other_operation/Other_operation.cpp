#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;
	int num;
	int den;
public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	Fraction operator + (Fraction right)
	{

		if (denominator_ == right.denominator_)
		{
			 num = numerator_ + right.numerator_;
			 den = denominator_;
		}
		else
		{
			num = (numerator_ * right.denominator_) + (right.numerator_ * denominator_);
			den = (denominator_ * right.denominator_);
		}
		return Fraction(num, den);
	}
	Fraction operator - (Fraction right)
	{

		if (denominator_ == right.denominator_)
		{
			num = numerator_ - right.numerator_;
			den = denominator_;
		}
		else
		{
			num = (numerator_ * right.denominator_) - (right.numerator_ * denominator_);
			den = (denominator_ * right.denominator_);
		}
		return Fraction(num, den);
	}
	Fraction operator * (Fraction right)
	{
	    num = numerator_ * right.numerator_;
		den = denominator_ * right.denominator_;
		return Fraction(num, den);
	}
	Fraction operator / (Fraction right)
	{
		num = numerator_ * right.denominator_;
		den = denominator_ * right.numerator_;
		return Fraction(num, den);
	}
	Fraction& operator ++ ()
	{
		num = numerator_ ++;
		den = denominator_ ++;
		return (*this);
	}
	Fraction& operator++(int)
	{
		num = numerator_;
		den = denominator_;
		return (*this);
	}

	Fraction& operator -- () 
	{
		num = numerator_ --;
		den = denominator_ --;
		return (*this);
	}

	Fraction& operator--(int)
{
		num = numerator_;
		den = denominator_;
		return --(*this);
	}

	void print() {
		for (;;) {
			if (((numerator_ % 2) == 0) && ((denominator_ % 2) == 0)) {
				numerator_ /= 2;
				denominator_ /= 2;
			}
			else if (((numerator_ % 3) == 0) && ((denominator_ % 3) == 0)) {
				numerator_ /= 3;
				denominator_ /= 3;
			}
			else if (((numerator_ % 5) == 0) && ((denominator_ % 5) == 0)) {
				numerator_ /= 5;
				denominator_ /= 5;
			}
			else if (((numerator_ % 7) == 0) && ((denominator_ % 7) == 0)) {
				numerator_ /= 7;
				denominator_ /= 7;
			}
			else {
				std::cout << numerator_ << "/" << denominator_ << "\n";
				break;
			}
		}
	}
};

int main(int argc, char** argv)
{
	int first_Num;
	int first_Den;
	int second_Num;
	int second_Den;
	std::cout << "Input Firs numerator: ";
	std::cin >> first_Num;
	std::cout << "Input Firs denominator: ";
	std::cin >> first_Den;
	std::cout << "Input Second numerator: ";
	std::cin >> second_Num;
	std::cout << "Input Second denominator: ";
	std::cin >> second_Den;

	Fraction f1(first_Num, first_Den);
	Fraction f2(second_Num, second_Den);

	Fraction sum_f1_f2 = f1 + f2;
	std::cout << first_Num << " / " << first_Den << " + " << second_Num << " / " << second_Den << " = "; 
	sum_f1_f2.print();
	Fraction dif_f1_f2 = f1 - f2;
	std::cout << first_Num << " / " << first_Den << " - " << second_Num << " / " << second_Den << " = ";
	dif_f1_f2.print();
	Fraction mul_f1_f2 = f1 * f2;
	std::cout << first_Num << " / " << first_Den << " * " << second_Num << " / " << second_Den << " = ";
	mul_f1_f2.print();
	Fraction dev_f1_f2 = f1 / f2;
	std::cout << first_Num << " / " << first_Den << " / " << second_Num << " / " << second_Den << " = ";
	dev_f1_f2.print();
	Fraction pp_f1_f2 = ++f1;
	std::cout << "++" <<  first_Num << " / " << first_Den << " = ";
	pp_f1_f2.print();
	Fraction ppmul_f1_f2 = pp_f1_f2 * f2;
	std::cout << "++" << first_Num << " / " << first_Den << " * " << second_Num << " / " << second_Den << " = ";
	ppmul_f1_f2.print();
	Fraction ppp_f1_f2 = f1++;
	std::cout << first_Num << " / " << first_Den << "++" << " = ";
	ppp_f1_f2.print();
	Fraction pppmul_f1_f2 = ppp_f1_f2 * f2;
	std::cout << first_Num << " / " << first_Den << "++" << " * " << second_Num << " / " << second_Den << " = ";
	pppmul_f1_f2.print();
	Fraction mm_f1_f2 = --f1;
	std::cout << "--" << first_Num << " / " << first_Den << " = ";
	mm_f1_f2.print();
	Fraction mmmul_f1_f2 = mm_f1_f2 * f2;
	std::cout << "--" << first_Num << " / " << first_Den << " * " << second_Num << " / " << second_Den << " = ";
	mmmul_f1_f2.print();
	Fraction mmp_f1_f2 = f1--;
	std::cout << first_Num << " / " << first_Den << "--" << " = ";
	mmp_f1_f2.print();
	Fraction mmpmul_f1_f2 = mmp_f1_f2 * f2;
	std::cout << first_Num << " / " << first_Den << "--" << " * " << second_Num << " / " << second_Den << " = ";
	mmpmul_f1_f2.print();
	return 0;
}