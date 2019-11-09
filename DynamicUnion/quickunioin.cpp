#include "quickunioin.h"
quickunioin::quickunioin(int N)
{
	s.resize(N);
	pid.resize(N);

	for (int i = 0; i < N; i++)
	{
		pid[i] = i;
		s[i] = 1;
	}
	
}

quickunioin::~quickunioin()
{
	s.clear();
	pid.clear();
}

int quickunioin::root(int i)
{
	while (i != pid[i])
	{
		pid[i] = pid[pid[i]]; //for path compression. To make tree length small
		i = pid[i];
	}
	return i;
}
bool quickunioin::connected(int p, int q)
{
	return root(p) == root(q);
}

void quickunioin::unioin(int p, int q)
{
	int i = root(p);
	int j = root(q);

	if (i == j)
		return;
	if (s[i] > s[j])
	{
		pid[j] = i;
		s[i] += s[j];
	}
	else {
		pid[i] = j;
		s[j] += s[i];
	}
}

void quickunioin::getroot(int i)
{
	cout << "Root of " << i << endl;
	while (i != pid[i])
	{
		i = pid[i];
		cout << i << " ";
	}
	cout << endl;
}
