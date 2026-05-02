include <iostream>
#include <vector>

using namespace std;

string value;
vector<vector<int>> adj;

void DFS(int cur, int level)
{
	cout << value[cur];

	for (int i = 0; i < adj.size(); ++i)
	{
		if (adj[cur][i])
			DFS(i, level + 1);
	}
}

int main()
{
	cin >> value;

	adj.resize(value.size());

	for (int i = 0; i < adj.size(); ++i)
	{
		for (int j = 0; j < adj.size(); ++j)
		{
			int n;
			cin >> n;
			adj[i].push_back(n);
		}
	}

	DFS(0, 0);

	return 0;
}