#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
	int x;
};

Node queue[10];
int head = 0;
int tail = 0;

void Enqueue(int data)
{
	tail += 1;

	if (tail >= 10) tail = 0;
	if (tail == head) return;

	queue[tail].x = data;
}

void Dequeue()
{
	if (head != tail)
	{
		head++;
		if (head >= 10) head = 0;
		cout << queue[head].x;
	}
}

int main()
{
	int input;
	cin >> input;
	for (int i = 0; i < input; ++i)
	{
		Enqueue(1);
		Enqueue(2);
		Enqueue(3);
		Dequeue();
		Dequeue();
		Dequeue();
	}

	return 0;
}