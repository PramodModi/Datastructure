//Circular linked list
#pragma once
#include<iostream>
using namespace std;

struct Node1 {
	int data;
	Node1* next;
};

class Dll
{
private:
	Node1* head, *tail;
	Node1* createNode(int data);

public:
	Dll();
	~Dll();
	int size();
	bool isEmpty();
	void displayAll();
	void deleteAll();
	void insert_beg(int data);
	void insert_end(int data);
	void insert(int pos, int data);
	void remove_beg();
	void remove_end();
	void remove(int pos);
};

