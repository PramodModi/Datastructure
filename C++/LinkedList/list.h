#pragma once
#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class list
{
private:
	Node* head;
	Node* createNode(int data);
public:
	list();
	~list();
	int size();
	bool isEmpty();
	void display();
	void deleteList();
	void insert_beg(int data);
	void insert_end(int data);
	void insert(int data, int pos);
	void remove_beg();
	void remove_end();
	void remove(int pos);

};

