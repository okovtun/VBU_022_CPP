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
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	void print()
	{
		cout << "X = " << this->x << "\tY = " << this->y << ";\n";
	}

	double distance(const Point& other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(pow(x_distance, 2) + pow(y_distance, 2));
	return distance;
}

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

	//Point C = 5;
	//C.print();

	Point CC = B;	//Copy constructor
	CC.print();

	cout << "\n====================== Method ==========================\n" << endl;
	cout << A.distance(B) << endl;
	cout << B.distance(A) << endl;
	cout << "\n===================== Function =========================\n" << endl;
	cout << distance(A, B) << endl;
	cout << "\n======================== End ===========================\n" << endl;
	cout << sizeof(Point) << endl;

	A.print();
	B.print();
}