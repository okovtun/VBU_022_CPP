#include<iostream>
using namespace std;

/*
1. Инкапсуляция - Сокрытие определенной части класса от внешнего мира;
	Модификаторы доступа
	private:
	public:
	protected:
	---------------------------------------------
	get/set - методы
	get - взять, получить
	set - установить, задать

	==============================================================
2. Наследование;
3. Полиморфизм;
*/

class Point	//Создавая класс(структуру) ...
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		/*if (y < 10)
		{
			this->y = y;
		}
		else
		{
			this->y = 10;
		}*/
		this->y = (y < 10) ? y : 10;
	}
	//Constructors:
	/*Point()	//Default constructor - это конструктор, который может быть вызван без параметров
	{
		x = y = double();
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	/*Point(double x)
	{
		this->x = x;
		this->y = double();
		cout << "Constructor:\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	void print()
	{
		cout << "X = " << this->x << "\tY = " << this->y << ";\n";
	}
};

//#define BASICS

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASICS
	int a;	//Объявление переменной 'a' типа 'int'.
	Point A;//Объявление переменной 'A' типа 'Point'
			//Создание объекста 'A' структуры 'Point'
	A.set_x(2);
	A.set_y(5);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point* pA = &A;
	cout << pA->get_x() << "\t" << pA->get_y() << endl;

	/*
	----------------------------------------------------
	.  - Оператор прямого доступа (Point operator - оператор точка);
	-> - Оператор косвенного доступа (Arrow operator - оператор стрелка);
	this
	----------------------------------------------------
	*/
#endif // BASICS

	Point A;	//Default constructor
	A.print();

	Point B(5, 2);
	B.print();

	Point C = 5;
	C.print();
}