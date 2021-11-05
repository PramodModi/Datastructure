#pragma once
#include<iostream>

using namespace std;

template<class T>

class MaxPQX
{
private:
	int N; //number of elements in array
	int c; //capacity of array
	T* pq;

	void swap(int l, int m)
	{
		T temp = pq[l];
		pq[l] = pq[m];
		pq[m] = temp;
	}

public:
	MaxPQX()
	{
		N = 0;
		c = 2;
		pq = new T[c];
	}
	~MaxPQX()
	{
		delete pq;
	}

	bool isEmpty()
	{
		return N == 0;
	}
	int size()
	{
		return N;
	}

	void resize(int newc)
	{
		T* newpq = new T[newc];
		for (int i = 0; i <= N; i++)
		{
			newpq[i] = pq[i];
		}
		c = newc;
		pq = newpq;
	}

	void swim(int k)
	{
		while (k > 0 && pq[k] > pq[ (k-1) / 2])
		{
			swap(k, (k-1) / 2);
			k = (k-1) / 2;
		}
	}
	void sink(int k)
	{
		while ((2 * k + 1) <= N)
		{
			int j = 2 * k +1;
			if (j < N and pq[j] < pq[j + 1])
				j++;
			if (pq[j] > pq[k])
			{
				swap(j, k);
				k = j;
			}
			else
				break;
		}
	}

	void insert(T x)
	{
		if (N == c)
			resize(2 * c);
		pq[N] = x;
		swim(N++);

	}

	T getMax()
	{
		if (isEmpty())
		{
			cout << "Empty PQ" << endl;
			return NULL;
		}
		return pq[0];
	}

	T delMax()
	{
		if (isEmpty())
		{
			cout << "Empty PQ" << endl;
			return NULL;
		}
		T retVal = pq[0];
		swap(0, N--);
		sink(0);
		if (N <= c / 4)
			resize(c / 2);
		return retVal;
	}

	void display()
	{
		if (isEmpty())
		{
			cout << "Empty PQ" << endl;
			return;
		}
		for (int i = 0; i < N; i++)
			cout << pq[i] << " ";
		cout << endl;
	}

};


