#include<iostream>
#include<Windows.h>
using namespace std;

enum Color
{
	blue = 0x09,
	green = 0x0A,
	red = 0x0C,
	default_color = 0x0B
};

class Shape
{
	Color color;
public:
	Shape(Color color):color(color)
	{
		this->color = color;
		cout << "ShapoeConstructor:\t" << this << endl;
	}
	virtual ~Shape()
	{
		cout << "ShapeDestructor:\t" << this << endl;
	}
	Color get_color()const
	{
		return color;
	}
	virtual double get_area() const = 0;
	virtual double get_perimeter() const = 0;
	virtual void draw()const = 0;
};

class Square:public Shape
{
	double side;
public:
	double get_side()const
	{
		return side;
	}
	void set_side(double side)
	{
		if (side >= 0)this->side = side;
		else side = 0;
	}
	//		Constructors:
	Square(Color color, double side):Shape(color)
	{
		set_side(side);
	}
	~Square()
	{
		cout << "SquareDestructor:\t" << this << endl;
	}

	//		Methods:
	double get_area()const
	{
		return side * side;
	}
	double get_perimeter()const
	{
		return side * 4;
	}
	void draw()const
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, get_color());
		for (int i = 0; i < side; i++)
		{
			for (int j = 0; j < side; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
		SetConsoleTextAttribute(hConsole, Color::default_color);
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	Square square(Color::blue, 5);
	cout << "Площадь квадрата: " << square.get_area() << endl;
	cout << "Периметр квадрата: " << square.get_perimeter() << endl;
	square.draw();
	//system("COLOR 09");
}