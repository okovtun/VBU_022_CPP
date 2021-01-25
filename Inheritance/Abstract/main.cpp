#include<iostream>
using namespace std;

class Animal
{
public:
	virtual void sound() = 0;
};

class Cat :public Animal
{
public:
	void sound()
	{
		cout << "ּÿף" << endl;
	}
};

class Dog :public Animal
{
public:
	void sound()
	{
		cout << "ֳאפ" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	//Animal animal;
	/*Cat cat;
	Dog hot;*/

	Animal* zoo[] =
	{
		new Cat(),
		new Dog(),
		new Cat(),
		new Cat()
	};
	for (Animal* i : zoo)
	{
		i->sound();
	}
}