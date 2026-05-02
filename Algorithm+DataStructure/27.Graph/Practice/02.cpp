#include <iostream>
#include <vector>

using namespace std;

struct ABC
{
	int data[4];
	int x;
};

int main()
{
	ABC a, b;

	for (int i = 0; i < 4; ++i)
	{
		a.data[i] = i + 1;
	}
	a.x = 10;

	for (int i = 0; i < 4; ++i)
	{
		b.data[i] = i + 7;
	}
	b.x = 15;

	ABC* p = &a;
	ABC* g = &b;

	for (int i = 0; i < 4; ++i)
	{
		cout << p->data[i];
	}
	cout << endl;
	cout << p->x << endl;

	for (int i = 0; i < 4; ++i)
	{
		cout << g->data[i];
	}
	cout << endl;
	cout << g->x;

	return 0;
}