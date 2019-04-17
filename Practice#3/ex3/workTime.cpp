/*
* Рассмотрим алгоритм случайной сортировки, примененный к массиву a[size] целых чисел:
* выбирается случайное число i из интервала от 1 до size и меняются местами
* элементы a[0] и a[i], процесс повторяется до тех пор, пока не будут 
* упорядочены все элементы массива. Каково ожидаемое время выполнения массива?
*/

#include <iostream>
#include <time.h>
using namespace std;

// сортировка методом прямого включения 
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

// функция вывода массива на экран
void showArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	/* ициниализация элементов программы */
	bool check = false;
	const int size = 4;
	int arr1[size];
	int arr2[size];
	/* ициниализация элементов программы */

	for (int i = 0; i < size; i++)
	{
		cout << "Element " << (i + 1) << ": ";
		cin >> arr1[i];
	}

	for (int i = 0; i < size; i++)
		arr2[i] = arr1[i];

	inclusionSort(arr1, size);

	clock_t start = clock(); // начало замера времени работы случайной сортировки
	cout << "Sort is started...\n";
	while (check == false)
	{
		int index = rand() % (size-1) + 1;
		int temp = arr2[0];
		arr2[0] = arr2[index];
		arr2[index] = temp;
		showArray(arr2, size);
		if (equal(begin(arr1), end(arr1), begin(arr2))) // проверка массивов на равенство
			check = true;
	}
	cout << "Sort is ended.";
	clock_t end = clock(); // конец замера времени работы случайной сортировки
	double seconds = (double) (end - start) / CLOCKS_PER_SEC; // время работы выбранного участка программы

	cout << "\nFirst array: ";
	showArray(arr1, size);
	cout << "Second array: ";
	showArray(arr2, size);

	cout << "The time: " << seconds << " seconds" << endl;

	return 0;
}


