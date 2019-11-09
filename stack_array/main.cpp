#include "stack_array.h"

int main()
{
	stack_array<int> s;
	s.push(2);
	s.push(3);
	s.push(6);
	s.push(4);
	s.push(1);

	s.display();
	cout<<s.top()<<endl;
	s.display();
	cout<<s.pop()<<endl;
	s.display();
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout << s.pop() << endl;
	s.display();
	return 0;
}