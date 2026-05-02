#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
	int x;
	char y;
};

Node queue[10];
int head = 0;
int tail = 0;

void push(int x, char y)
{
	if (tail < 10)
	{
		queue[tail].x = x;
		queue[tail].y = y;
		++tail;
	}
}

Node pop()
{
	if (head < 10 && head <= tail && tail > 0)
		return queue[head++];

}

int main()
{
	int input;

	cin >> input;

	for (int i = 0; i < input; ++i)
	{
		push(i + 1, 'A' + i);
	}

	while (input--)
	{
		Node data = pop();
		cout << data.x << " " << data.y << endl;
	}


	return 0;
}