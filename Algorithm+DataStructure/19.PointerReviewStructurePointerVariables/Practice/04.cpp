#include <iostream>

using namespace std;

struct Node
{
	int x;
	Node* next;
};

int main(void)
{
	Node a, b, c;

	a.x = 3;
	a.next = &b;
	a.next->x = 5;
	b.next = &c;
	b.next->x = 4;


	return 0;
}