#include<iostream>
#include<string.h>
using namespace std;

class String
{
	int size;	//������ ������ � ������
	char* str;	//��������� �� ������ � ������������ ������
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	//		Constructors:
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:" << this << endl;
	}
	String(const char str[])
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)
			this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveConstructor:" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyConstructor:" << this << endl;
	}
	~String()
	{
		delete[] str;
		cout << "Destructor:\t" << this << endl;
	}

	//			Operators
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveAssignment:" << this << endl;
		return *this;
	}

	const char& operator[](int i)const
	{
		//�������� �������������� (Subscript operator) ���������� �������� �� �������

		return this->str[i];
	}
	char& operator[](int i)
	{
		//�������� �������������� (Subscript operator) ���������� �������� �� �������

		return this->str[i];
	}

	//			Methods
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}
istream& operator>>(istream& is, String& obj)
{
	return is >> obj.get_str();
}

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
	{
		//cat.get_str()[i] = left.get_str()[i];
		cat[i] = left[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		cat.get_str()[left.get_size() - 1 + i] = right.get_str()[i];
	}
	return cat;
}

#define delimiter "\n---------------------------------------\n"

//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	String str;		//Default constructor
	str.print();
	String str1 = "Hello";//Single argument constructor
	str1.print();
	String str2 = str1;	//Copy constructor
	str2.print();

	String str3;	//Default constructor
	str3 = str2;	//Copy assignment
	str3.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	String str1, str2, str3;
	str1 = str2 = str3 = "Hello";
	str1.print();
	str2.print();
	str3.print();

	str1 = str1;
	str1.print();
#endif // ASSIGNMENT_CHECK



	String str1 = "Hello";
	String str2 = "World";
	cout << str1 << endl;
	cout << str2 << endl;
	cout << delimiter << endl;
	//String str3 = str1 + " " + str2;	//Move constructor
	String str3;
	str3 = str1 + str2;
	cout << delimiter << endl;
	cout << str3 << endl;
	cout << delimiter << endl;
	cout << str1 + str2 << endl;
	cout << delimiter << endl;
	/*String name;
	cout << "������� ���� ���: ";
	cin >> name;
	cout << name << endl;;*/
}