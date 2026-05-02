#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
	int data;
	int level;
};

vector<vector<int>> adj(6, vector<int>(6));

void BFS(int startIdx, int startLevel)
{
	queue<Node> que;
	que.push(Node{ startIdx, startLevel });

	while (!que.empty())
	{
		Node cur = que.front();
		que.pop();

		if (cur.data % 2) cout << cur.data << " ";

		for (int i = 0; i < adj.size(); ++i)
		{
			if (adj[cur.data][i])
			{
				que.push(Node{ i, cur.level + 1 });
			}
		}

	}

}

int main()
{
	for (int i = 0; i < adj.size(); ++i)
	{
		for (int j = 0; j < adj[i].size(); ++j)
		{
			cin >> adj[i][j];
		}
	}

	BFS(0, 0);

	return 0;
}