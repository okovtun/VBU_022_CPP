#include<iostream>
#include<string>
#include<deque>
#include<forward_list>
#include<list>
#include<map>
#include<set>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

//#define DEQUE
//#define FORWARD_LIST
//#define LIST
//#define MAP
#define SET

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef DEQUE
	//Dequeue (Double-ended queue - двунаправленна€ очередь) это контейнер, 
	//который хранит данные в виде списка динамических массивов.

	deque<int> dq = { 3,5,8,13,21 };
	for (deque<int>::iterator it = dq.begin(); it != dq.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
	/*dq.push_back(34);
	dq.push_front(2);*/
	dq.emplace_front(2);
	dq.emplace_back(34);
	for (int i = 0; i < dq.size(); i++)
	{
		cout << dq[i] << tab;
	}
	cout << endl;
	cout << dq.size() << endl;

#endif // DEQUEUE

#ifdef FORWARD_LIST
	forward_list<int> list = { 3,5,8,13,21 };
	for (forward_list<int>::iterator it = list.begin(); it != list.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
	list.push_front(2);
	list.push_front(1);
	list.insert_after(list.before_begin(), 123);
	for (int i : list)	cout << i << tab; cout << endl;
	int value;
	int index;
	cout << "¬ведите добавл€емое значение: "; cin >> value;
	cout << "¬ведите индекс добавл€емого значени€: "; cin >> index;
	forward_list<int>::iterator position = list.begin();
	//for (int i = 0; i < index-1; i++)position++;
	std::advance(position, index);
	list.insert_after(position, value);
	for (int i : list)cout << i << tab; cout << endl;
#endif // FORWARD_LIST

#ifdef LIST
	//list - двусв€зный список
	list<int> list{3, 5, 8, 13, 21};
	/*for (int& i : list)
	{
		i = rand() % 100;
	}*/
	list.push_back(34);
	list.push_front(2);
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;
#endif // LIST

#ifdef MAP
	//map - это контейнер, который хранит данные в виде бинарного дерева.
	// аждым элементом этого дерева €вл€етс€ пара: ключ-значение
	//pair<key, value>
	//map €вл€етс€ уникальным деревом, т.е., ключи в нем не повтор€ютс€.
	//multimap - неуникальное дерево, в котором ключи могут повтор€тьс€.
	/*map<int, string> week =
	{
		pair<int, string>(0, "Sunday"),
		pair<int, string>(1, "Monday"),
		pair<int, string>(2, "Tuesday"),
		pair<int, string>(2, "Tuesday"),
		pair<int, string>(2, "Tuesday"),
		pair<int, string>(2, "Tuesday"),
		pair<int, string>(2, "Tuesday"),
		pair<int, string>(2, "Tuesday"),
		pair<int, string>(3, "Wednesday"),
		pair<int, string>(4, "Thursday"),
		pair<int, string>(5, "Friday"),
		pair<int, string>(6, "Saturday")
	};
	for (map<int, string>::iterator it = week.begin(); it != week.end(); it++)
	{
		cout << it->first << tab << it->second << endl;
	}*/

	map<string, list<string>> dictionary = 
	{
		pair<string, list<string>>("space", {"космос", "пробел", "простанство"}),
		pair<string, list<string>>("merry", {"веселый", "свадьба"}),
		pair<string, list<string>>("driver", {"водитель", "машинист", "управл€юща€ программа"}),
		pair<string, list<string>>("current", {"ток", "текущий", "денежна€ единица"}),
		pair<string, list<string>>("fire", {"огонь", "пожар"})
	};
	/*for (map<string, list<string>>::iterator it = dictionary.begin(); it != dictionary.end(); it++)
	{
		cout << it->first << ":";
		cout.width(10);
		for (list<string>::iterator value = it->second.begin(); value != it->second.end(); value++)
			cout << *value << ", ";
		cout << "\b\b;\n";
	}*/
	for (pair<string, list<string>> i : dictionary)
	{
		//cout << typeid(i).name() << endl;
		cout << i.first << ":\t";
		for (string val : i.second)
			cout << val << ", ";
		cout << "\b\b;\n";
	}
#endif

#ifdef SET
	//’ранит объекты в виде Ѕинарного дерева.
	multiset<int> numbers;
	for (int i = 0; i < 50; i++)
	{
		numbers.insert(rand() % 10);
	}
	for (int i:numbers)
	{
		cout << i << tab;
	}
	cout << endl;
	cout << "Size:" << numbers.size() << endl;
#endif
}