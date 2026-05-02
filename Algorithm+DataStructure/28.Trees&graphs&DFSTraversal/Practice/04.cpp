#include <iostream>
#include <vector>

using namespace std;

vector<int> value;
vector<vector<int>> adj;

void InitValueNAdj()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		value.push_back(i);
	}

	adj.resize(n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int data;
			cin >> data;
			adj[i].push_back(data);
		}
	}
}

void Searching(int cur, int level)
{
	cout << value[cur] << " ";

	for (int i = 0; i < adj.size(); ++i)
	{
		if (adj[cur][i])
		{
			Searching(i, level + 1);
		}
	}
}


int main()
{
	InitValueNAdj();
	Searching(0, 0);

	return 0;
}