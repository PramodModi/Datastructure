#pragma once
#include<iostream>

using namespace std;

template<class T>

class MaxPQ
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
	MaxPQ()
	{
		N = 0;
		c = 2;
		pq = new T[c];
	}
	~MaxPQ()
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
		for (int i = 1; i <= N; i++)
		{
			newpq[i] = pq[i];
		}
		c = newc;
		pq = newpq;
	}

	void swim(int k)
	{
		while (k > 1 && pq[k] > pq[k / 2])
		{
			swap(k, k / 2);
			k = k / 2;
		}
	}
	void sink(int k)
	{
		while (2 * k <= N)
		{
			int j = 2 * k;
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
		if (N == c - 1)
			resize(2 * c);
		pq[++N] = x;
		swim(N);

	}

	T getMax()
	{
		if (isEmpty())
		{
			cout << "Empty PQ" << endl;
			return NULL;
		}
		return pq[1];
	}

	T delMax()
	{
		if (isEmpty())
		{
			cout << "Empty PQ" << endl;
			return NULL;
		}
		T retVal = pq[1];
		swap(1, N--);
		sink(1);
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
		for (int i = 1; i <= N; i++)
			cout << pq[i] << " ";
		cout << endl;
	}

};

