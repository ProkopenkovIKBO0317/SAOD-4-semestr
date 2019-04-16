#pragma once

/*
* односвязный список.
* реализация
*/

template<typename T>
class List
{
public:
	List();
	~List();

	void push_back(T data); // метод добавления элемента в конец 
	int size() { return Size; } // возвращает текущщее количество элементов 

	T& operator[](const int index); // итерация по списка


private:

	template<typename T>
	class Node
	{
	public:
		Node *pNext; // указатель на следующий элемент
		T data;
		Node(T data = T(), Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
		~Node() {}

	};
	int Size; // переменная для подсчета кол-ва элементов списка
	Node<T> *head; // голова списка, указатель на голову списка

};

