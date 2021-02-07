#include<iostream>
using namespace std;

#define tab "\t"

class Element
{
	int Data;		//Значение элемента
	Element* pNext;	//Адрес следующего элемента
public:
	Element(int Data, Element* pNext = nullptr):Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	friend class List;
};

class List
{
	Element* Head;	//Указатель на начальный (нулевой) элемент списка.
public:
	List()
	{
		Head = nullptr;	//Если Голова содержит 0, значит список пуст
		cout << "LConstructor:\t" << this << endl;
	}
	~List()
	{
		cout << "LDestructor:\t" << this << endl;
	}

	//			Добавление элементов
	void push_front(int Data)	//Добавляет значение в начало списка
	{
		/*
		//1) Создаем новый элемент
		Element* New = new Element(Data);
		//2) Присоединяем НОВЫЙ элемент к списку
		New->pNext = Head;
		//3)Говорим, что НОВЫЙ элемент является НАЧАЛОМ (Head) списка:
		Head = New;*/

		Head = new Element(Data, Head);
	}
	void push_back(int Data)	//Добавляет значение в конец списка
	{
		if (Head == nullptr)//Если список пуст
		{
			push_front(Data);
			return;
		}
		//0) Создать элемент:
		//Element* New = new Element(Data);
		//1) Дойти до последнего элемента
		Element* Temp = Head;
		while (Temp->pNext != nullptr)
			Temp = Temp->pNext;
		//2) Прикрепить добавляемы элемент к концу списка
		Temp->pNext = new Element(Data);
	}

	void insert(int Index, int Data)
	{
		//1) Доходим до нужного элемента:
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
		{
			if (Temp->pNext == nullptr)return;
			Temp = Temp->pNext;
		}
		Temp->pNext = new Element(Data, Temp->pNext);
	}

	//			Methods
	void print()
	{
		Element* Temp = Head;	//Temp - это итератор.
		//Итератор - это указатель, при помощи которого можно получить доступ 
		//к элементам структуры данных.
		while (Temp != nullptr)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;	//Переход на следующий элемент
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;	//Размер списка
	cout << "Введите размер списка: "; cin >> n;
	List list;
	/*list.push_back(3);
	list.push_back(5);
	list.push_back(8);
	list.push_back(13);
	list.push_back(21);*/
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list.print();
	list.push_back(123);
	list.print();
	
	int index;
	int data;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> data;
	list.insert(index, data);
	list.print();
}