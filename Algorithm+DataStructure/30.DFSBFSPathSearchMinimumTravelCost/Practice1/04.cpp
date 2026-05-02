#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> value = { 0, 1, 2, 3, 4, 5 };
vector<vector<bool>> map =
{
	{0, 0, 0, 0, 1, 0},
	{1, 0, 1, 0, 0, 1},
	{1, 0, 0, 1, 0, 0},
	{1, 1, 0, 0, 0, 0},
	{0, 1, 0, 1, 0, 1},
	{0, 0, 1, 1, 0, 0}
};
vector<bool> visited(value.size(), false);
struct Node
{
	int data;
	int level;
};

void BFS(int start)
{
	queue<Node> que;
	que.push(Node{ start, 0 });

	while (!que.empty())
	{
		Node cur = que.front();
		que.pop();

		cout << cur.data << endl;

		for (int i = 0; i < map[cur.data].size(); ++i)
		{
			if (map[cur.data][i] && !visited[i])
			{
				visited[i] = true;
				que.push(Node{ i, cur.level + 1 });
			}
		}
	}
}

int main()
{
	int start;

	cin >> start;

	visited[start] = true;

	BFS(start);

	return 0;
}