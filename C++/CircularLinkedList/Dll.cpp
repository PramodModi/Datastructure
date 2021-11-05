#include "Dll.h"

Dll::Dll()
{
	head = tail = NULL;
}
Dll::~Dll()
{
	deleteAll();
}
Node1* Dll::createNode(int data)
{
	Node1* newNode = new Node1;
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
int Dll::size()
{
	if (head == NULL)
	{
		return 0;
	}

	int s = 0;
	Node1* cur = head;
	do {
		s++;
		cur = cur->next;
	} while (cur != head);

	return s;
}

bool Dll::isEmpty()
{
	return (head == NULL);
}

void Dll::displayAll()
{
	if (isEmpty())
	{
		cout<< "List is Empty" <<endl;
		return;
	}
	Node1* cur = head;
	do {
		cout << cur->data << endl;
		cur = cur->next;
	} while (cur != head);

}

void Dll::deleteAll()
{
	if (isEmpty())
	{
		return;
	}
	Node1* cur = head;
	while (cur != tail)
	{
		head = head->next;
		delete cur;
		cur = head;
	}
	delete head;
	head = tail = NULL;
	
}

void Dll::insert_beg(int data)
{
	Node1* newNode1 = createNode(data);
	if (head == NULL)
	{
		head = newNode1;
		tail = newNode1;
		head->next = tail;
		return;
	}
	tail->next = newNode1;
	newNode1->next = head;
	head = newNode1;
}

void Dll::insert_end(int data)
{
	Node1* newNode1 = createNode(data);
	if (head == NULL)
	{
		head = newNode1;
		tail = newNode1;
		head->next = tail;
		return;
	}
	tail->next = newNode1;
	newNode1->next = head;
	tail = newNode1;
}

void Dll::insert(int pos, int data)
{
	if (pos<0 || pos>size())
	{
		cout << "Out of range" << endl;
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

	Node1* cur = head, * prev = NULL;
	for (int i = 0; i < pos; i++)
	{
		prev = cur;
		cur = cur->next;
	}
	Node1* newNode1 = createNode(data);
	prev->next = newNode1;
	newNode1->next = cur;
}
void Dll::remove_beg()
{
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
		return;
	}
	Node1* cur = head;
	head = head->next;
	tail->next = head;
	delete cur;
}

void Dll::remove_end()
{
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
		return;
	}
	Node1* cur = head;

	while (cur->next != tail)
	{
		cur = cur->next;
	}
	tail = cur;
	cur = cur->next;
	tail->next = head;
	delete cur;
}

void Dll::remove(int pos)
{
	if (pos<0 || pos>=size())
	{
		cout << "Out of range" << endl;
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

	Node1* cur = head, * prev = NULL;
	for (int i = 0; i < pos; i++)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = cur->next;
	delete cur;
}
