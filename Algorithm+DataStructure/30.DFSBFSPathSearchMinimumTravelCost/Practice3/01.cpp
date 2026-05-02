#include <iostream>
#include <vector>

using namespace std;

int n;
vector<bool> visited;
vector<int> path(3, 0);
int cnt = 0;

void DFS(int curV, int curLev)
{
	if (curLev == 3)
	{
		++cnt;
		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		if (visited[i]) continue;

		visited[i] = true;
		path[curLev] = i;
		DFS(i, curLev + 1);
		visited[i] = false;
		path[curLev] = 0;
	}
}

int main()
{
	cin >> n;

	visited.resize(n + 1, false);

	DFS(-1, 0);

	cout << cnt;
}