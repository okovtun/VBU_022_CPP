#include"Fraction.h"

//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define ARITHMETIC_OPERATORS_CHECK
//#define INCREMENT_CHECK
//#define COMPARISON_CHECK

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

#ifdef COMPARISON_CHECK
	Fraction A(4, 1, 2);
	cout << delimiter;
	cout << A << endl;
	cout << delimiter;
	Fraction B = A;	//Copy constructor
	cout << (A == B) << endl;
#endif // COMPARISON_CHECK


	//double a = 2;
	//cout << (int)a << endl;//C-like notation
	//cout << int(a) << endl;//Functional notation
	//int b = a;
	//cout << b << endl;
	//cout << typeid(2 + 3.5).name() << endl;
	//cout << (double)7 / 2 << endl;

	//Single argument constructor

	int a = 2;		//No conversion
	double b = 3;	//From less to more
	Fraction A = (Fraction)5;	//Single argument constructor
	Fraction B;		//Default constructor
	B = (Fraction)8;
	Fraction C(2, 1, 2);
	double d = (double)C;
	cout << d << endl;
	cout << B << endl;
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

//operator type()
//{
//	
//}