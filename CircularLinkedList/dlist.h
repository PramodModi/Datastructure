#pragma once

#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class dlist
{
private:
	Node* head;
	Node* createNode(int data);
public:
	dlist();
	~dlist();
	int size();
	bool isEmpty();
	void displayAll();
	void deleteList();
	void insert_beg(int data);
	void insert_end(int data);
	void insert(int pos, int data);
	void remove_beg();
	void remove_end();
	void remove(int pos);

};

