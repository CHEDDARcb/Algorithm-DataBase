#include <iostream>
#include <queue>

using namespace std;

const int custumerNum = 12;
const int maxDoorNum = 4;
const int custumer[custumerNum] = { 0, 1, 0, 1, 0, 1, 2, 3, 2, 3, 2, 3 };
const int dir[2] = { -1, 1 };
struct Node
{
	int ai;
	int bi;
	int cost;
	int ci;
};

int BFS(int ai, int bi)
{
	queue<Node> que;
	que.push({ ai, bi, 0, 0 });

	int n = 1;
	while (!que.empty())
	{
		cout << n++ << endl;
		Node cur = que.front();
		que.pop();

		int ci;
		for (ci = cur.ci; ci < custumerNum; ++ci)
		{
			if (cur.ai == custumer[ci] ||
				cur.bi == custumer[ci])
				break;
		}

		if (ci == custumerNum)
			return cur.cost;

		for (int i = 0; i < 2; ++i)
		{
			int newAI = cur.ai + dir[i];

			if (newAI < 0 || newAI > maxDoorNum)
				continue;

			if (newAI == cur.bi)
				continue;

			que.push({ newAI, cur.bi, cur.cost + 1, ci });
		}

		for (int i = 0; i < 2; ++i)
		{
			int newBI = cur.bi + dir[i];

			if (newBI < 0 || newBI > maxDoorNum)
				continue;

			if (newBI == cur.ai)
				continue;

			que.push({ cur.ai, newBI, cur.cost + 1, ci });
		}
	}
}

int main(void)
{
	int ai, bi;
	bool bTurn = false;
	for (int k = 0; k <= maxDoorNum; ++k)
	{
		int n;
		cin >> n;

		if (n == 1 && !bTurn)
		{
			ai = k;
			bTurn = true;
		}
		else if (n == 1 && bTurn)
			bi = k;
	}

	int result = BFS(ai, bi);

	cout << result;

	return 0;
}