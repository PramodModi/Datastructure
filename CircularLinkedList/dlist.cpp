#include "dlist.h"

dlist::dlist()
{
	head = NULL;
}

dlist::~dlist()
{
	deleteList();
}

void dlist::deleteList()
{
	if (head == NULL)
		return;
	
	Node* cur = head;
	Node* prev = cur;
	while (cur->next != head)
	{
		cur = cur->next;
		prev->next = cur->next;
		prev = cur;
		cur = cur->next;
		delete prev;
	}
	delete head;
	head = NULL;
	
}
int dlist::size()
{
	if (head == NULL)
		return 0;
	int s = 0;
	Node* cur = head;
	do
	{
		cur = cur->next;
		s++;
	} while (cur != head);
	return s;
}

bool dlist::isEmpty()
{
	return size() == 0;
}

void dlist::displayAll()
{
	if (isEmpty())
	{
		cout << "Empty dlist" << endl;
		return;
	}
	Node* cur = head;
	do
	{
		cout << cur->data << endl;
		cur = cur->next;
	} while (cur != head);
}

Node* dlist::createNode(int data)
{
	Node* newnode = new Node();
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}
void dlist::insert_beg(int data)
{
	Node* newNode = createNode(data);
	if (isEmpty())
	{
		head = newNode;
		newNode->next = head;
		return;
	}

	Node* cur = head;
	while (cur->next != head) {
		cur = cur->next;
	}

	newNode->next = head;
	cur->next = newNode;
	head = newNode;
}
void dlist::insert_end(int data)
{
	Node* newNode = createNode(data);
	if (isEmpty())
	{
		head = newNode;
		newNode->next = head;
		return;
	}

	Node* cur = head;
	while (cur->next != head) {
		cur = cur->next;
	}

	newNode->next = head;
	cur->next = newNode;
	
}

void dlist::insert(int pos, int data)
{
	if (size() < pos)
	{
		cout << "out of index" << endl;
		return;
	}

	if (pos == 0)
	{
		insert_beg(data);
		return;
	}

	if (pos == size())
	{
		insert_end(data);
		return;
	}

	Node* newNode = createNode(data);

	Node* cur = head;
	Node* prev = cur;

	for (int i = 0; i < pos; i++)
	{
		prev = cur;
		cur = cur->next;
	}

	newNode->next = cur;
	prev->next = newNode;

}

void dlist::remove_beg()
{
	if (isEmpty())
	{
		cout << "dlist is empty" << endl;
		return;
	}
	if (head->next == head) {
		delete head;
		head = NULL;
		return;
	}

	Node* cur = head;
	while (cur->next != head)
		cur = cur->next;

	Node* temp = head;
	head = head->next;
	cur->next = head;
	delete temp;

}

void dlist::remove_end()
{
	if (isEmpty())
	{
		cout << "dlist is empty" << endl;
		return;
	}
	if (size() == 1)
	{
		remove_beg();
		return;
	}

	Node* cur = head;
	Node* temp = cur;
	while (cur->next != head) {
		temp = cur;
		cur = cur->next;
	}
	temp->next = cur->next;
	delete cur;
	
}

void dlist::remove(int pos)
{
	if (isEmpty())
	{
		cout << "dlist is empty" << endl;
		return;
	}
	if (size() <= pos)
	{
		cout << "Out of Index" << endl;
		return;
	}

	if (pos == 0)
	{
		remove_beg();
		return;
	}
	if (pos == size()-1)
	{
		remove_end();
		return;
	}

	Node* cur = head;
	Node* prev = head;

	for (int i = 0; i < pos; i++)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = cur->next;
	cur->next = NULL;
	delete cur;
}