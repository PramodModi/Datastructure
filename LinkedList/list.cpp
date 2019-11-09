#include "list.h"
list::list()
{
	head = NULL;
}

list::~list()
{
	deleteList();
}

void list::deleteList()
{
	Node* cur = head;
	Node* prev;
	while (cur != NULL)
	{
		prev = cur;
		cur = cur->next;
		delete prev;
	}
	head = NULL;
}
int list::size()
{
	int s = 0;
	Node* cur = head;

	while (cur != NULL)
	{
		cur = cur->next;
		s++;
	}
	return s;
}

bool list::isEmpty()
{
	return size() == 0;
}

void list::display()
{
	if(isEmpty())
	{
		cout << "Empty List" << endl;
		return;
	}
	Node* cur = head;
	while (cur != NULL)
	{
		cout << cur->data << endl;
		cur = cur->next;
	}
}

Node* list::createNode(int data)
{
	Node* newnode = new Node();
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}
void list::insert_beg(int data)
{
	Node* newNode = createNode(data);
	if (isEmpty())
	{
		head = newNode;
		return;
	}
	newNode->next = head;
	head = newNode;
}
void list::insert_end(int data)
{
	Node* newNode = createNode(data);
	if (isEmpty())
	{
		head = newNode;
		return;
	}

	Node* cur = head;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}

	cur->next = newNode;
}

void list::insert(int data, int pos)
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

void list::remove_beg()
{
	if (isEmpty())
	{
		cout << "List is empty" << endl;
		return;
	}

	Node* cur = head;
	head = head->next;
	delete cur;
	
}

void list::remove_end()
{
	cout << "In remove_end" << endl;
	if (isEmpty())
	{
		cout << "List is empty" << endl;
		return;
	}
	if (size() == 1)
	{
		remove_beg();
		return;
	}

	Node* cur = head;
	Node* prev = cur;

	while (cur->next != NULL)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = NULL;
	delete cur;
}

void list::remove(int pos)
{
	if (isEmpty())
	{
		cout << "List is empty" << endl;
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
	//cur->next = NULL;
	delete cur;
}