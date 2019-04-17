// Practice3ex2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <intrin.h>
#include <time.h>
using namespace std;

// сортировка с помощью прямого включения
void inclusionSort(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int value = arr[i]; // запоминаем значение элемента
		int index = i; // и его индекс

		while ((index > 0) && (arr[index - 1] > value))
		{
			// смещаем другие элементы к концу массива пока они меньше index
			arr[index] = arr[index - 1];
			index--; // смещаем просмотр к началу массива
		}
		arr[index] = value; // рассматриваемый элемент помещаем на освободившееся место
	}
}

// сортировка с помощью прямого обмена
void bubbleSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = (size - 1); j > i; j--) // для всех элементов после i-ого
		{
			if (arr[j - 1] > arr[j]) // если текущий элемент меньше предыдущего
			{
				int temp = arr[j - 1]; // меняем их местами
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

// сортировка с помощью прямого выбора
void selectionSort(int* arr, int size)
{
	int min, temp;
	for (int i = 0; i < size; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

// функция вывода массива
void showArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

unsigned __int64 tick()
{
	return (__rdtsc());
}

int main()
{
	unsigned __int64 start, finish;
	int size;

	try
	{
		cout << "Enter size of array: "; cin >> size;
		if (size < 0)
		{
			cout << "Size of array must be more then 0\n";
			exit(0);
		}
		if (!size)
		{
			throw size;
		}
		// создание массивов
		int* arr1 = new int[size];
		int* arr2 = new int[size];
		int* arr3 = new int[size];

		// заполнение первого массива
		for (int i = 0; i < size; i++)
		{
			cout << "Element " << (i + 1) << ": ";
			cin >> arr1[i];
			if (!(arr1[i] > 0) && !(arr1[i] < 0) && !(arr1[i] == 0))
			{
				cout << "Incorrect data entry!\n";
				exit(0);
			}
		}

		// заполнение остальных массивов
		for (int i = 0; i < size; i++)
		{
			arr2[i] = arr1[i];
			arr3[i] = arr1[i];
		}

		// the first alghoritm
		start = tick();
		selectionSort(arr1, size);
		finish = tick();
		double res1 = finish - start;
		// the second alghoritm
		start = tick();
		bubbleSort(arr2, size);
		finish = tick();
		double res2 = finish - start;
		// the third alghoritm
		start = tick();
		inclusionSort(arr3, size);
		finish = tick();
		double res3 = finish - start;

		cout << "Sorted array: ";
		showArray(arr1, size);

		cout << "The time Inclusion sort: " << res3 << " processor ticks."  << endl;
		cout << "The time Bubble sort: " << res2  << " processor ticks." << endl;
		cout << "The time Selection sort: " << res1 << " processor ticks." << endl;
	}
	catch (int e)
	{
		cout << "Incorrect data entry! The programe will be stoped.\n";
	}

	return 0;
}


