#pragma once
#include<iostream>
using namespace std;

template <class T>

class queue
{
private:
	struct Node {
		T data;
		Node* next;
	};

	Node* f, * r;

public:
	queue()
	{
		f = NULL;
		r = NULL;
	}
	~queue()
	{
		delete f;
			
	}

	bool isEmpty()
	{
		return f == NULL;
	}

	void enqueue(T d)
	{
		Node* newnode = new Node;
		newnode->data = d;
		newnode->next = NULL;
		if (isEmpty())
		{
			f = r = newnode;
		}
		else
		{
			r->next = newnode;
			r = newnode;
		}
	}

	T dequeue()
	{
		Node* temp = f;
		f = f->next;
		T d = temp->data;
		delete temp;
		return d;
	}

	void display()
	{
		Node* t = f;
		while (t != NULL)
		{
			cout << t->data << " ";
			t = t->next;
		}
		cout << endl;
	}

};
