/*
* Написать программу нахождения k наименьших элементов в массиве длинной n.
*/

#include <iostream>
using namespace std;

// inclusion sort
void inclusionSort(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int value = arr[i];
		int index = i;

		while ((index > 0) && (arr[index - 1] > value))
		{
			arr[index] = arr[index - 1];
			index--;
		}
		arr[index] = value;
	}
}

int main()
{
	int k, length;
	cout << "Enter length array: "; cin >> length;
	int* arr = new int[length];
	for (int i = 0; i < length; i++)
	{
		cout << "Element " << (i + 1) << ": ";
		cin >> arr[i];
	}
	cout << "Basic array:";
	for (int i = 0; i < length; i++)
		cout << " " << arr[i];
	cout << "\nEnter count less elements: "; cin >> k;
	inclusionSort(arr, length);
	cout << k << " less elements from basic array:";
	for (int i = 0; i < k; i++)
		cout << " " << arr[i];
	cout << endl;
	system("pause");
	return 0;
}
