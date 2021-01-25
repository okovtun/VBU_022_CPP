#include<iostream>
#include<string>
using namespace std;

class Human
{
	string last_name;
	string first_name;
	int age;
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	int get_age()const
	{
		return age;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}
	//			Constructors:
	Human(const string& last_name, const string& first_name, int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//			Methods:
	virtual void print()
	{
		cout << last_name << " " << first_name << ", " << age << " лет.\n";
	}
};

class Student :public Human
{
	string specialty;
	int year;	//год обучения
	int rating;	//успеваемость
	int attendance;	//посещаемость
public:
	const string& get_specilaty()const
	{
		return specialty;
	}
	int get_year()const
	{
		return year;
	}
	int get_rating()const
	{
		return rating;
	}
	int get_attendance()const
	{
		return attendance;
	}
	void set_specialty(const string& specialty)
	{
		this->specialty = specialty;
	}
	void set_year(int year)
	{
		this->year = year;
	}
	void set_rating(int rating)
	{
		this->rating = rating;
	}
	void set_attendance(int attendance)
	{
		this->attendance = attendance;
	}
	//			Constructors:
	Student
	(
		const string& last_name, const string& first_name, int age,
		const string& specialty, int year, int rating, int attendance
	):Human(last_name, first_name, age)
	{
		set_specialty(specialty);
		set_year(year);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	//			Methods:
	void print()
	{
		Human::print();
		cout << year << "-й курс, " << "успеваемость " << rating << "%, посещаемость " << attendance << "%;\n";
	}
};

class Teacher :public Human
{
	string specialty;
	int experience;
public:
	const string& get_specialty()const
	{
		return specialty;
	}
	int get_experience()const
	{
		return experience;
	}
	void set_specialty(const string& specialty)
	{
		this->specialty = specialty;
	}
	void set_experience(int experience)
	{
		this->experience = experience;
	}
	//			Constructors:
	Teacher
	(
		const string& last_name, const string& first_name, int age,
		const string& specialty, int experience
	) :Human(last_name, first_name, age)
	{
		set_specialty(specialty);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	//			Methods:
	void print()
	{
		Human::print();
		cout << "Специальность:\t" << specialty << ", опыт преподавания " << experience << " лет.\n";
	}
};

//#define INHERITANCE

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef INHERITANCE
	/*Human vasya("Тупенко", "Василий", 18);
vasya.print();*/

	Student vasya("Тупенко", "Василий", 18, "РПО", 1, 70, 80);
	vasya.print();

	Teacher walter("White", "Walter", 50, "Chemestry", 25);
	walter.print();
#endif // INHERITANCE


	//Inheritance -> Generalization
	//Polymorphism-> Specialisation
	//cout << "\n-----------------------------------\n";
	/*Human* p_student = &vasya;
	Human* p_teacher = &walter;
	p_student->print();
	p_teacher->print();*/

	Human* group[] =
	{
		new Student("Гулюкин", "Олег", 35, "Разработка сетевых приложений", 1, 100, 100),
		new Student("Сиренко", "Ирина", 30, "AI & BigData", 1, 100, 100),
		new Student("Шниткин", "Денис", 25, "Разработка Android приложений", 1, 95, 90),
		new Teacher("Олег", "Анатольевич", 36, "Разработка Android приложений", 5)
	};
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		group[i]->print();
	}
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete group[i];
	}
}