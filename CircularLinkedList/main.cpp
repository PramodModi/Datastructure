#include "dlist.h"
#include "Dll.h"


int main()
{
	//Dll l;
	dlist l;
	l.insert_beg(2);
	l.insert_beg(3);
	l.insert_beg(4);
	l.insert_beg(5);
	l.insert_end(6);
	l.insert_end(7);
	l.insert_end(8);
	l.insert_end(9);
	l.displayAll();
	cout << "Size = "<< l.size() <<endl;
	l.remove(1);
	cout << "After remove at pos 1" << endl;
	l.displayAll();
	l.remove(0);
	cout << "After remove at pos 0" << endl;
	l.displayAll();
	l.remove(6);
	cout << "After remove at pos 6" << endl;
	l.displayAll();
	l.remove_end();
	cout << "After remove at end" << endl;
	l.displayAll();
	l.remove_beg();
	cout << "After remove at beg" << endl;
	l.displayAll();
	
	l.insert(1, 4);
	cout << "After insert 4 at pos 1" << endl;
	l.displayAll();
	
	return 0;
}