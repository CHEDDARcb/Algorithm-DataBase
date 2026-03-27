#include <iostream>
#include <print>
#include <queue>

int queue[30] = { 1, 2 };
int level[30] = { 1, 1 };
int parent[30] = { -1, -1 };
int head = 0;
int tail = 2;

void print(int idx)
{
	while (true)
	{
		if (idx == -1)
			break;

		std::println("{} Ãâ·Â", queue[idx]);
		idx = parent[idx];
	}
}

int main(void)
{
	while (true)
	{
		for (size_t i = 0; i < 2; ++i)
		{
			queue[tail] = i + 1;
			level[tail] = level[head] + 1;
			parent[tail] = head;
			tail++;
		}

		head++;

		if (level[head] == 3)
			break;
	}

	for (size_t i = head; i < tail; ++i)
	{
		print(i);
		std::println("-------");
	}
}