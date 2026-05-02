#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> value = { 0, 1, 2, 3, 4, 5 };
vector<vector<bool>> map =
{
	{0, 1, 0, 0, 1, 0},
	{0, 0, 1, 0, 0, 1},
	{0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0}
};
vector<bool> visited;

struct Node
{
	int data;
	int level;
};
void BFS(int startIdx)
{
	queue<Node> que;
	que.push(Node{ startIdx, 0 });

	while (!que.empty())
	{
		Node cur = que.front();
		que.pop();

		cout << cur.data << " ";

		for (int i = 0; i < map[cur.data].size(); ++i)
		{
			if (map[cur.data][i] && !visited[i])
			{
				que.push(Node{ i, cur.level + 1 });
			}
		}
	}
}

int main()
{
	int startIdx;

	cin >> startIdx;

	visited.resize(value.size(), false);
	visited[startIdx] = true;

	BFS(startIdx);

	return 0;
}