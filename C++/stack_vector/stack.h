#pragma once
#include<iostream>
#include<vector>

using namespace std;
template<class T>
class stack
{
private:
	vector<T> data;

public:
	int size();
	void push(T d);
	T pop();
	T top();
	void display();
	friend ostream & operator <<(ostream & out, const stack<T>& s);
};

template<class T>
int stack<T>::size()
{
	return data.size();
}

template<class T>
void stack<T>::push(T d)
{
	data.push_back(d);
}

template<class T>
T stack<T>::pop()
{
	if (data.size() == 0)
	{
		cout << "Stack is empty" << endl;
		return;
	}
	return data.pop_back();
}

template<class T>
T stack<T>::top()
{
	if (data.size() == 0)
	{
		cout << "Stack is empty" << endl;
		return;
	}
	return data.back();
}

template<class T>
void stack<T>::display()
{
	for (int i = 0; i < size(); i++)
	{
		cout << data[i]<<endl;
	}
}




