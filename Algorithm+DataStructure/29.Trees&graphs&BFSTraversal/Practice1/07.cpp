#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	int idx;
	int level;
};

string adj;

void InputAdj()
{
	cin >> adj;
}

void BFS(int startIdx, int level)
{
	queue<Node> que;
	que.push(Node{ startIdx, level });

	while (!que.empty())
	{
		Node cur = que.front();
		que.pop();

		cout << adj[cur.idx] << " ";

		int left = cur.idx * 2;
		int right = cur.idx * 2 + 1;
		int nxtLev = cur.level + 1;
		if (left < adj.size() &&
			adj[left] != '0')
			que.push(Node{ left, nxtLev });
		if (right < adj.size() &&
			adj[right] != '0')
			que.push(Node{ right, nxtLev });
	}

}

int main()
{
	InputAdj();

	BFS(1, 0);

	return 0;
}