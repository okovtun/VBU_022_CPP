#include<iostream>
using namespace std;

class Box
{
	double length;	//Длина
	double width;	//Ширина
	double height;	//Высота
	bool closed;	//Коробка закрыта
protected:
	char* content;
public:
	void open()
	{
		closed = false;
	}
	void close()
	{
		closed = true;
	}
};

class GiftBox :public Box
{
	char* cover;	//Обвертка
	char* bantik;
public:
	void show()
	{
		this->
	}
};

void main()
{
	Box box;
	box.open();
	GiftBox gb;
	gb.close();
}