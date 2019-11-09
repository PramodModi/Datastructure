#include "list.h"

int main()
{
	list l;
	l.insert_beg(2);
	l.insert_beg(3);
	l.insert_beg(4);
	l.insert_beg(5);
	l.insert_end(6);
	l.insert_end(7);
	l.insert_end(8);
	l.insert_end(9);
	l.remove(4);
	l.display();
	cout << "After insert at pos 1" << endl;
	l.insert(4, 1);
	l.display();
	return 0;
}