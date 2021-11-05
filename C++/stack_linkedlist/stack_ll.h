#pragma once
#include <iostream>
using namespace std;

template <class T>

class stack_ll
{
private:
	struct Node
	{
		T data;
		Node* next;
	};

	Node* head;

public:
	stack_ll()
	{
		head = NULL;
	}

	~stack_ll()
	{
		delete head;
		head = NULL;
	}

	bool isEmpty()
	{
		return head == NULL;
	}

	void push(T d)
	{
		Node* temp = new Node;
		temp->data = d;
		temp->next = head;
		head = temp;
	}

	T pop()
	{
		if (isEmpty())
		{
			cout << "Stack is Empty" << endl;
			return NULL;
		}

		T d = head->data;
		Node* temp = head;
		head = head->next;
		delete temp;
		return d;

	}

	T top()
	{
		if (isEmpty())
		{
			cout << "Stack is Empty" << endl;
			return NULL;
		}
		return head->data;
	}

	void display()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	
		cout << endl;
	}
};
