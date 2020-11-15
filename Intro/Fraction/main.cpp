#include<iostream>
using namespace std;

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
};

//#define CONSTRUCTORS_CHECK

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
