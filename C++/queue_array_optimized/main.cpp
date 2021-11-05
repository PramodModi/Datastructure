#include "queue.h"

int main()
{
	queue<int> q;

	q.enqueue(1);
	q.enqueue(2);
	q.display();

	cout << q.dequeue() << endl;
	q.enqueue(3);
	q.display();
	q.enqueue(4);
	q.display();
	q.enqueue(5);
	q.enqueue(6);
	q.enqueue(7);
	q.enqueue(8);
	q.enqueue(9);
	q.enqueue(10);
	q.enqueue(11);
	q.display();
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	q.display();
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	q.display();

	return 0;
}