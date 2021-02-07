#include<iostream>
using namespace std;

//List

void Print(int arr[], const int n);
int* push_back(int* arr, int& n, int value);

void main()
{
	setlocale(LC_ALL, "");
	int n = 5;
	int* arr = new int[n]{ 3,5,8,13,21 };
	cout << *arr << endl;
	Print(arr, n);
	arr = push_back(arr, n, 123);
	Print(arr, n);
	delete[] arr;
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
}

int* push_back(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
		buffer[i] = arr[i];
	delete[] arr;
	buffer[n] = value;
	n++;
	return buffer;
}