#pragma once
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

/////////////////////////////////////////////////////////////////////////////////////////////////

//					CLASS DECLARATION - ОБЪЯВЛЕНИЕ КЛАССА

class Fraction;
inline Fraction operator-(Fraction left, Fraction right);
inline Fraction operator*(Fraction left, Fraction right);
inline Fraction operator/(Fraction left, Fraction right);
ostream& operator<<(ostream& os, const Fraction& obj);

class Fraction
{
	int integer;	//Целая часть
	int numerator;	//Числитель
	int denominator;//Знаменатель
public:
	int get_integer()const;
	int get_numerator()const;
	int get_denomiantor()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);
	//			Constructors:
	Fraction();
	Fraction(int integer);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();

	//				Operators:
	Fraction& operator=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);

	//			Increment/Decrement
	Fraction& operator++();	//Prefix increment
	Fraction operator++(int);	//Suffix increment

	//			Type cast operators:
	explicit operator int();
	explicit operator double();

	//			Methods:
	void print()const;
	void print_address()const;
	Fraction& to_proper();
	Fraction& to_improper();
	Fraction inverted();
	Fraction& reduce();
};
//						Class declaration end
///////////////////////////////////////////////////////////////////////////////////////////////////////////////