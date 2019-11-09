#pragma once
#include <iostream>
#include <vector>
using namespace std;

class quickunioin
{
private:
	vector<int> pid;
	vector<int> s;
	int root(int i);

public:
	quickunioin(int N);
	~quickunioin();
	bool connected(int p, int q);
	void unioin(int p, int q);
	void getroot(int i);
	

};

