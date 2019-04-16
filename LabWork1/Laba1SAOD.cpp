// struct_lab1.cpp : Defines the entry point for the console application
//

#include "pch.h"
#include "Set.h"
#include "List.h"
#include <iostream>
using namespace std;


int main()
{
	int size = 0; // количество точек
	cout << "Write how many points you want?" << endl; cin >> size;
	Point* mas = new Point[size];
	cout << "Write " << size << " pairs of numbers. First number is X coordinate, second number is Y coordinate" << endl;
	for (int i(0); i < size; i++)
	{
		int j, k;
		cout << (i + 1) << " pair" << endl;
		cout << "X coord: "; cin >> j;
		cout << "Y coord: "; cin >> k;
		mas[i].x = j;
		mas[i].y = k;
	}

	Set* s = new Set(mas, size); // создаем множество точек на основе массива, который ввел пользователь

	cout << "The biggest trinagle's perimetr is: " << Set::checkSet(*s) << endl;

	system("pause");

}
