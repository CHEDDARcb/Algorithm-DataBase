#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<bool>> adj;
vector<int> parents;
vector<int> rnk;

void Input()
{
	cin >> n;

	adj.resize(n, vector<bool>(n, false));
	parents.resize(n, -1);
	rnk.resize(n, 0);

	for(int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int input;
			cin >> input;
			adj[i][j] = input;
		}
	}
}

int GetParent(int c)
{
	if (parents[c] < 0)
		return c;

	int ret = GetParent(parents[c]);
	return parents[c] = ret;
}

bool MakeGroup(char c1, char c2)
{
	int a = GetParent(c1 - 'A');
	int b = GetParent(c2 - 'A');

	if (a == b) return true;

	if (rnk[a] < rnk[b])
		swap(a, b);
	parents[b] = a;
	if (rnk[a] == rnk[b])
		rnk[a]++;

	return false;
}

int main(void)
{
	Input();

	bool isCycle = false;
	for (int i = 0; i < adj.size(); ++i)
	{
		for (int j = 0 + i; j < adj[i].size(); ++j)
		{
			if (adj[i][j])
				if (isCycle = MakeGroup('A' + i, 'A' + j))
					break;
		}
		if (isCycle)
			break;
	}

	cout << (isCycle ? "발견" : "미발견");

	return 0;
}