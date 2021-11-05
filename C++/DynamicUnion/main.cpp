#include "quickunioin.h"

int main()
{
	quickunioin q(9);
	q.unioin(2, 3);
	//cout << "root of 3 : " << q.root(3) << endl;
	//cout << "root of 2 : " << q.root(2) << endl;
	q.unioin(3, 5);
	//cout << "root of 5 : " << q.root(5) << endl;
	//cout << "2 and 5 are connected ? " << q.connected(2, 5) << endl;
	q.unioin(7, 8);
	//cout << "root of 7 : " << q.root(7) << endl;
	//cout << "root of 8 : " << q.root(8) << endl;
	//cout << "7 and 5 are connected ? " << q.connected(7, 5) << endl;
	q.unioin(6, 8);
	//cout << "root of 6 : " << q.root(6) << endl;
	q.unioin(6, 1);
	//cout << "root of 1 : " << q.root(1) << endl;
	q.unioin(8, 3);
	cout << "root of 1 : " << endl;
	q.getroot(1);
	cout << "root of 2 : "  << endl;
	q.getroot(2);
	cout << "root of 3 : " <<endl;
	q.getroot(3);
	cout << "root of 5 : " <<endl;
	q.getroot(5);
	cout << "root of 6 : " << endl;
	q.getroot(6);
	cout << "root of 7 : " << endl;
	q.getroot(7);
	cout << "root of 8 : " << endl;
	q.getroot(8);

	return 0;
}