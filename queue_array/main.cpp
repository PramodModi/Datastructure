#include "queue_array.h"

int main()
{
	queue_array<int> q;

	q.enqueue(1);
	q.enqueue(2);
	q.display();

	cout << q.dequeue() << endl;
	q.enqueue(3);
	q.display();
	q.enqueue(4);
	q.display();


	return 0;
}