#include<iostream>
using namespace std;

class Box
{
	double length;	//�����
	double width;	//������
	double height;	//������
	bool closed;	//������� �������
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
	char* cover;	//��������
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