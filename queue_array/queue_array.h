#pragma once
#include <iostream>
using namespace std;

template<class T>
class queue_array
{
private:
	T* a;
	int f, r, capacity;

public:
	queue_array()
	{
		capacity = 1;
		a = new T[capacity];
		f = -1;
		r = -1;
	}

	~queue_array()
	{
		delete a;
		a = NULL;
	}

	bool isEmpty()
	{
		return f == -1;
	}

	bool isFull()
	{
		if ((f == 0 && r == capacity-1)
			|| (f != 0 && r == (f-1) % capacity ))
			return true;
		else
			return false;
	}

	void resize()
	{
		int s = capacity;
		capacity = s * 2;
		T* temp = new T[capacity];

		if (r - f >= 0)
		{
			for (int i = 0; i < s; i++)
				temp[i] = a[i];
		}
		else
		{
			for (int i = 0; i <= r; i++)
				temp[i] = a[i];

			int j = capacity;
			for (int i = s - 1; i >= f; i--)
			{
				temp[--j] = a[i];
				
			}
			f = j;
		}
		a = temp;
	}

	void enqueue(T d)
	{
		
		if (isEmpty())
		{
			f = 0;
			r = 0;
			a[r] = d;
			return;
			
		}
		if (isFull())
		{
			resize();
		}
		if (f != 0 && r == capacity-1)
		{
			r = 0;
			a[r] = d;
 		}
		else
		{
			a[++r] = d;
		}

		
	}

	T dequeue()
	{
		if (isEmpty())
		{
			cout << "Queue is empty" << endl;
			return NULL;
		}
		T retval = a[f];
		if (f == r)
		{
			f = -1;
			r = -1;
		}
		else
			f = (f+1)% capacity;
		return retval;
	}

	T front()
	{
		return a[f];

	}

	T rear()
	{
		return a[r];
	}

	void display()
	{
		int i = f;
		while (i != r)
		{
			cout << a[i] << " ";
			i = (i + 1) % capacity;
		}
		cout << a[r] << endl;
	}

};