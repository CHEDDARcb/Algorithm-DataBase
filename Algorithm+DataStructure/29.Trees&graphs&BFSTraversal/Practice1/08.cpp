#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node
{
	int idx;
};

vector<vector<int>> adj =
{
	{0, 1, 0, 0 ,0, 0, 0, 0, 0, 0}, //A
	{0, 0, 1, 1, 1, 1, 0, 0, 0, 0}, //B
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //C
	{0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, //D
	{0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, //E
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //F
	{0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, //G
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //H
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //I
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}  //J
};
string value = "ABCDEFGHIJ";

int InputNode()
{
	char input;

	cin >> input;

	return input - 'A';
}

void BFS(int startIdx)
{
	queue<Node> que;
	que.push(Node{ startIdx });

	while (!que.empty())
	{
		Node cur = que.front();
		que.pop();

		cout << value[cur.idx] << " ";

		for (int i = 0; i < adj.size(); ++i)
		{
			if (adj[cur.idx][i])
				que.push(Node{ i });
		}
	}
}

int main()
{
	int startIdx = InputNode();

	BFS(startIdx);

	return 0;
}