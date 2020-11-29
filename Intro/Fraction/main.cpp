#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Fraction;
inline Fraction operator-(Fraction left, Fraction right);
inline Fraction operator*(Fraction left, Fraction right);
inline Fraction operator/(Fraction left, Fraction right);

class Fraction
{
	int integer;	//Целая часть
	int numerator;	//Числитель
	int denominator;//Знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denomiantor()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		this->denominator = denominator ? denominator : 1;
	}
	//			Constructors:
	Fraction()
	{
		integer = numerator = 0;
		denominator = 1;
		cout << "DefaultConstructor:" << this << endl;
	}
	Fraction(int integer)
	{
		//Конструктор с одним параметром
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1argConstructor:" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//				Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	//			Increment/Decrement
	Fraction& operator++()	//Prefix increment
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)	//Suffix increment
	{
		/*Fraction old = *this;
		integer++;
		return old;*/
		integer++;
		(*this - 1).print();
		return (*this - 1);
	}

	//			Methods:
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		if (integer == 0 && numerator == 0)cout << 0;
		cout << endl;
	}
	void print_address()const
	{
		cout << "Object:\t\t" << this << "\n";
		cout << "Integer:\t" << &integer << "\n";
		cout << "Numerator:\t" << &numerator << "\n";
		cout << "Denominator:\t" << &denominator << "\n";
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction inverted()
	{
		this->to_improper();
		/*Fraction inverted(denominator, numerator);
		return inverted;*/
		return Fraction(denominator, numerator);
	}
	Fraction& reduce()
	{
		//Сокращение дроби по алгоритму Евклида.
		int more, less, rest;
		if (numerator < denominator)
		{
			less = numerator;
			more = denominator;
		}
		else
		{
			less = denominator;
			more = numerator;
		}
		/*do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);*/
		for (rest = 1; rest; more = less, less = rest)
			rest = more % less;
		int GCD = more;	//GCD - Greatest Common Dividor (Наибольший общий делитель - НОД)
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
};

inline Fraction operator-(Fraction left, Fraction right)
{
	Fraction result(
		left.get_integer() - right.get_integer(),
		left.get_numerator() * right.get_denomiantor() - right.get_numerator() * left.get_denomiantor(),
		left.get_denomiantor() * right.get_denomiantor()
	);
	return result.to_proper().reduce();
}

inline Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction result(left.get_numerator() * right.get_numerator(), left.get_denomiantor() * right.get_denomiantor());
	/*result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denomiantor() * right.get_denomiantor());*/
	//result.to_proper();
	return result.to_proper().reduce();
}
Fraction operator/(Fraction left, Fraction right)
{
	return left * right.inverted();
}

bool operator==(const Fraction& left, const Fraction& right)
{
	/*if (left.get_integer() == right.get_integer() &&
		left.get_numerator() == right.get_numerator() &&
		left.get_denomiantor() == right.get_denomiantor())
	{
		return true;
	}
	else
	{
		return false;
	}*/

	return left.get_integer() == right.get_integer() &&
		left.get_numerator() == right.get_numerator() &&
		left.get_denomiantor() == right.get_denomiantor();
}

ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_integer())cout << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())cout << "(";
		cout << obj.get_numerator() << "/" << obj.get_denomiantor();
		if (obj.get_integer())cout << ")";
	}
	if (obj.get_integer() == 0 && obj.get_numerator() == 0)cout << 0;
	return os;
}

//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define ARITHMETIC_OPERATORS_CHECK
//#define INCREMENT_CHECK

#define delimiter "\n---------------------------------------\n";
#define PI 3.14

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;	//Default constructor
	A.print();
	A.print_address();

	Fraction B = 5;//Single argument constructor
	B.print();
	B.print_address();

	Fraction C(1, 2);
	C.print();
	C.print_address();

	Fraction D(2, 3, 4);
	D.print();
	D.print_address();
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;

	Fraction A, B, C;
	cout << "\n---------------------------------------\n";
	A = B = C = Fraction(1, 2, 3);
	cout << "\n---------------------------------------\n";

	//Fraction A(3, 4);
	//A.print();
	//Fraction B(4, 5);
	//B.print();
	//Fraction C;
	//C = A;	//CopyAssignment (operator=)
	//C.print();  
#endif // ASSIGNMENT_CHECK

#if defined ARITHMETIC_OPERATORS_CHECK
	PI;
	int a = 2;
	int b = 3;
	//int c = a * b;
	//cout << c << endl;
	a *= b;
	Fraction A(2, 3, 4);
	Fraction B(5, 7, 8);
	//Fraction C = A * B;	C.print();
	//A *= B;	A.print();
	//Fraction C = A / B; C.print();
	A /= B;
	A.print();
	A.reduce().print();
	A.print();
#endif

#ifdef INCREMENT_CHECK
	for (double i = 0.25; i < 15; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
	cout << "\n----------------------------------------\n";
	//(Fraction(1, 1) - Fraction(1, 4)).print();
	(Fraction(2, 4) - Fraction(1, 4)).print();
	cout << "\n----------------------------------------\n";
	Fraction i(1, 2);
	Fraction j = i++;
	i.print();
	j.print();
#endif // INCREMENT_CHECK

	Fraction A(4, 1, 2);
	cout << delimiter;
	cout << A << endl;
	cout << delimiter;
	Fraction B = A;	//Copy constructor
	cout << (A == B) << endl;
}
/*
---------------------------------
int operator+(Cat other)
{

}
---------------------------------
		Overloading rules:
1. Перегрузить можно только СУЩЕСТВУЮЩИЕ оперторы
	+	перегружается
	++	перегружается
	*	перегружается
	**	НЕ перегружается
2. НЕ все существующие оперторы можно перегрузить. Не перегружаются
	?: - тернарный оператор;
	.  - оператор прямого доступа;
	.*
	:: - оператор разрешения видимости
	#
	##
3. Перегруженные оперторы сохраняют приоритет;
4. Нельзя изменить поведение операторов со свтроенными типами.
---------------------------------
*/
