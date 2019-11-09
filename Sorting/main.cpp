#include<iostream>
#include<algorithm>
#include "MaxPQ.h"
#include "MinPQ.h"
#include "MaxPQX.h"
using namespace std;

void swap(int a[], int pos1, int pos2)
{
	int temp = a[pos1];
	a[pos1] = a[pos2];
	a[pos2] = temp;
}

//Selection sort, find the minimium item in the list, swap with ith item. i = 0 at the start.
void selectionSort(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int min = i;

		for (int j = i; j < size; j++)
		{
			if (a[j] < a[min])
				min = j;
		}

		swap(a, min, i);
	}
}

//This is good for partial sorted array. swap the adjuscent item untill left of ith item is sorted.
void insertionSort(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int j = i;
		while (j > 0 && a[j] < a[j - 1])
		{
			swap(a, j, j - 1);
			j--;
		}

	}
}

void shellSort(int a[], int size)
{
	//find the highest value of h
	int h = 1;
	while (h < size / 3)
	{
		h = 3 * h + 1;
	}

	//Shell sort for h. This is simlar to insertion sort, rather than 1 increment in the position
	//increase to h. Repeat it untill h =1

	while (h >= 1)
	{
		//insertion sort for h increment
		for (int i = h; i < size; i++)
		{
			int j = i;
			while (j >= h and (a[j]<a[j-h]))
			{
				swap(a, j, j - h);
				j = j - h;
			}
		
		}

		h = h / 3;
	}

}

//Merge sort

//Merge two sorted arrays.

void merge(int a[], int l, int m, int r)
{
	int n1 = (m - l) + 1;
	int n2 = (r - m);

	int* a1 = new int[n1];
	int* a2 = new int[n2];

	for (int i = 0; i < n1; i++)
		a1[i] = a[l + i];
	for (int j = 0; j < n2; j++)
		a2[j] = a[m + 1+ j];

	int i = 0, j = 0, k = l;

	while (i < n1 and j < n2)
	{
		if (a1[i] <= a2[j])
		{
			a[k++] = a1[i++];
		}
		else
		{
			a[k++] = a2[j++];
		}
	}

	while (i < n1)
		a[k++] = a1[i++];
	while (j < n2)
		a[k++] = a2[j++];
}

//Recurssive 
void mergeSortRec(int a[], int l, int r)
{
	if (l >= r)
		return;
	int m = l + (r - l) / 2;

	mergeSortRec(a, l, m);
	mergeSortRec(a, m + 1, r);
	merge(a, l, m, r);
}

//Iterative or Bottom up
void mergeSort(int a[], int n)
{
	int c, l; //c is the capacity of smaller arrays, and l is the initial position
	for (c = 1; c < n; c = 2 * c)
	{
		for (l = 0; l < n - c; l = l + 2 * c)
		{
			int m = l + c - 1;
			int r = min(l + 2 * c - 1, n - 1);
			merge(a, l, m, r);
		}
	}
}

//Merge two arrays with O(1) space complexity. Final output would be two array in sorting order.

void mergeX(int a1[], int n1, int a2[], int n2)
{
	
	if (a1[n1 - 1] <= a2[0])
		return;
	if (a2[n2 - 1] <= a1[0])
	{
		for (int i = n2 - 1; i >= 0; i--)
		{
			int temp = a1[n1 - 1];
			int j;
			for (j = n1 - 2; j >= 0; j--)
			{
				a1[j + 1] = a1[j];
			}
			a1[j] = a2[i];
			a2[i] = temp;
		}
	}
	else
	{
		for (int i = n2 - 1; i >= 0; i--)
		{
			int temp = a1[n1 - 1];
			int j;
			for (j = n1 - 2; j >= 0; j--)
			{
				if (a2[i] < a1[j])
					a1[j + 1] = a1[j];
				else
					break;
			}
			a1[j+1] = a2[i];
			a2[i] = temp;
		}
	}
}

//Quick sort

int partition(int a[], int l, int r)
{
	int pv = a[l];
	int i = l + 1;
	int j = r - 1;

	while (true)
	{
		while (a[i] < pv)
		{
			if (i == r-1)
				break;
			i++;
		}

		while (a[j] > pv)
		{
			if (j == l)
				break;
			j--;
		}

		if (i >= j)
			break;
		swap(a, i, j);
	}
	swap(a, j, l);
	return j;
}


void quickSort(int a[], int l, int r)
{
	if (l >= r)
		return;
	int j = partition(a, l, r);
	quickSort(a, l, j);
	quickSort(a, j + 1, r);
}

//Quick 3 way
void ThreeWayPartition(int a[], int l, int r, int& i, int& j)
{
	int k = a[l];
	i = l + 1;
	j = r - 1;

	while (i <= j)
	{
		if (a[i] < k)
		{
			swap(a, i++, l++);
		}
		else if (a[i] > k)
		{
			swap(a, i, j--);
		}
		else
			i++;
	}
	i = l;

}

void quickSort3way(int a[], int l, int r)
{
	if (l >= r)
		return;
	int i, j;
	ThreeWayPartition(a, l, r, i, j);
	quickSort3way(a, l, i);
	quickSort3way(a, j + 1, r);


}

//Select kth smallest element.
//Use partition, all elements smaller than partition point will be in left, all elements greater than partition point would be in right
//Suppose, j is the partition point, then, for kth smallest, if k is less than j, partition the left subarray otherwise
//partition the right subarray, untill j == k

int kSmall(int a[], int k, int size)
{
	int l = 0, hi = size;
	while (l < hi)
	{
		int j = partition(a, l, hi);
		if (j < k)
			l = j+1;
		else if (j > k)
			hi = j;
		else
			return a[k];
	}
	return a[k];
}


//Heap sort
//step 1: Build heap using bottomup approach.
//step 2: Remove maximum one at a time
//	Exchange 1st element with last element, leave last element by reducing size by 1

void sink(int pq[], int k, int N)
{
	while ((2 * k + 1) <= N)
	{
		int j = 2 * k +1;
		if (j < N and pq[j] < pq[j + 1])
			j++;
		if (pq[k] < pq[j])
		{
			swap(pq, k, j);
			k = j;
		}
		else
			break;
			
	}
}

//N is size -1
void heapSort(int pq[], int N)
{
	//Build heap with bottom up approach
	for (int k = (N-1) / 2; k >= 0; k--)
	{
		sink(pq, k, N);
	}

	//sort the heap
	while (N > 0)
	{
		swap(pq, 0, N--);
		sink(pq, 0, N);
	}

}

void display(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{
	
	int a[] = { 3, 5, 2, 7,8,9,25, 22, 11, 19, 1 };
	
	int s = sizeof(a) / sizeof(a[0]);
	//display(a, s);
	//insertionSort(a, s);
	//selectionSort(a, s);
	//shellSort(a, s);
	//mergeSortRec(a, 0, s-1);
	//mergeSort(a, s);
	//quickSort(a, 0, s);
	/*quickSort3way(a, 0, s);
	display(a, s);
	int b[] = {3,5,8,9,12,15};
	int s1 = sizeof(b) / sizeof(b[0]);
	display(b, s1);
	mergeX(a, s, b, s1);
	display(a, s);
	display(b, s1);*/
	//int k = 4;
	//cout << "ksmall element :" << kSmall(a, k-1, s)<<endl;
	//cout << "kLarge element :" << kSmall(a, s-k, s) << endl;
	/*MaxPQ<int> pq;
	pq.insert(3);
	pq.insert(5);
	pq.insert(2);
	pq.insert(7);
	pq.insert(8);
	pq.insert(9);
	pq.insert(25);
	pq.insert(22);
	pq.insert(11);
	pq.insert(19);
	pq.insert(1);
	pq.display();

	for(int i = 0; i<11;i++)
		cout << pq.delMax()<<endl; */

	MaxPQX<int> pq;
	pq.insert(3);
	pq.insert(5);
	pq.insert(2);
	pq.insert(7);
	pq.insert(8);
	pq.insert(9);
	pq.insert(25);
	pq.insert(22);
	pq.insert(11);
	pq.insert(19);
	pq.insert(1);
	pq.display();

	for(int i = 0; i<11;i++)
		cout << pq.delMax()<<endl;

	/*cout << "**********Min PQ************" << endl;
	MinPQ<int> mpq;
	mpq.insert(3);
	mpq.insert(5);
	mpq.insert(2);
	mpq.insert(7);
	mpq.insert(8);
	mpq.insert(9);
	mpq.insert(25);
	mpq.insert(22);
	mpq.insert(11);
	mpq.insert(19);
	mpq.insert(1);
	mpq.display();

	for (int i = 0; i < 11; i++)
		cout << mpq.delMin() << endl;*/
	
	/*cout << "************Heapsort***********" << endl;
	display(a, s);
	heapSort(a, s-1);
	display(a, s);*/
	return 0;  
}