#pragma once
#include <iostream>

using namespace std;

template<class T>

class queue
{
private:
	T* a;
	int f; //front position in queue
	int r;//rear position in queue
	int n; //number of element in queue
	int c; // capacity of array

public:
	queue()
	{
		f = r = n = 0;
		c = 2;
		a = new T[c];
	}
	~queue()
	{
		delete a;
	}

	bool isEmpty()
	{
		return n == 0;
	}

	bool isFull()
	{
		return n == c;
	}

	void resize(int capacity)
	{
		T* temp = new T[capacity];
		for (int i = 0; i < n; i++)
			temp[i] = a[(f + i) % c];
		f = 0;
		r = n;
		c = capacity;
		a = temp;
	}

	void enqueue(T d)
	{
		if (isFull())
		{
			resize(c * 2);
		}
		a[r++] = d;
		n++;
		if (r == c)
			r = 0;
	}

	T dequeue()
	{
		if (isEmpty())
		{
			cout << "Queue is Empty" << endl;
			return NULL;
		}
		T retval = a[f++];
		n--;
		if (f == c)
			f = 0;
		if (n > 0 && n <= (c / 4))
			resize(c / 2);

		return retval;
	}

	T front()
	{
		if (isEmpty())
		{
			cout << "Queue is Empty" << endl;
			return NULL;
		}
		return a[f];
	}

	void display()
	{
		if (isEmpty())
		{
			cout << "Queue is Empty" << endl;
			return;
		}

		for (int i = 0; i < n; i++)
			cout << a[(f + i) % n] << " ";

		cout << endl;
	}

};