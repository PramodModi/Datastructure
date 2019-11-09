#pragma once
#include <iostream>
using namespace std;

template <class T>

class stack_array {
private:
	T* a;
	int capacity;
	int size;

public:
	stack_array()
	{
		size = 0;
		capacity = 1;
		a = new T[capacity];
	}

	~stack_array()
	{
		delete a;
	}

	bool isEmpty()
	{
		return size == 0;
	}
	void resize(int c)
	{
		T* tempa = new T[c];
		for (int i = 0; i < size; i++)
		{
			tempa[i] = a[i];
		}

		delete a;
		a = tempa;
	 }

	void push(T data)
	{
		if (size == capacity)
		{
			capacity = size * 2;
			resize(capacity);
		}
		a[size++] = data;

		
	}

	T pop()
	{
		if (isEmpty())
		{
			cout << "Stack is empty" << endl;
			return NULL;
		}

		T temp = a[--size];
		if (size > 0 and size <= (capacity / 4))
		{
			capacity = capacity / 4;
			resize(capacity);
		}
		return temp;
	}

	T top()
	{
		return a[size - 1];
	}

	void display()
	{
		if (isEmpty())
		{
			cout << "Stack is empty" << endl;
			return;
		}

		for (int i = size-1; i >= 0; i--)
			cout << a[i] << " ";

		cout << endl;
	}
};