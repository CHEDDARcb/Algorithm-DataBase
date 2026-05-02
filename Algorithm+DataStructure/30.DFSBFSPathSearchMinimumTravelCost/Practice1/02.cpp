#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

vector<vector<int>> map =
{
	{0, 0, 1, 0, 2, 0},
	{5, 0, 3, 0, 0, 0},
	{0, 0, 0, 0, 0, 7},
	{2, 0, 0, 0, 8, 0},
	{0, 0, 9, 0, 0, 0},
	{4, 0, 0, 7, 0, 0}
};
vector<int> value = { 0, 1, 2, 3, 4, 5 };
vector<bool> visited;
int cost = 0;
int start;

void DFS(int cur, int level)
{
	cout << value[cur] << " " << cost << endl;

	for (int i = 0; i < map[cur].size(); ++i)
	{
		if (map[cur][i] && !visited[i])
		{
			visited[i] = true;
			cost += map[cur][i];

			DFS(i, level + 1);
		}
	}
}

int main()
{
	visited.resize(value.size(), false);

	cin >> start;

	visited[start] = true;

	DFS(start, 0);

	return 0;
}