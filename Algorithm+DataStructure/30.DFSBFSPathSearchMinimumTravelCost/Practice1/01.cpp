#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

vector<char> value = { '0', '1', '2', '3', '4', '5' };
vector<vector<bool>> map =
{
	{0, 0, 1, 1, 0, 1},
	{0, 0, 0, 1, 1, 1},
	{0, 0, 0, 0, 1, 1},
	{0, 0, 0, 0, 0, 0},
	{1, 0, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0}
};
vector<bool> visited;
int start;

void DFS(int curIdx, int lev)
{
	cout << value[curIdx] << " ";

	for (int i = 0; i < map[curIdx].size(); ++i)
	{
		if (map[curIdx][i] && !visited[i])
		{
			visited[i] = true;
			DFS(i, lev + 1);
			//visited[i] = false;
		}
	}
}

int main()
{
	cin >> start;

	visited.resize(value.size(), false);
	visited[start] = true;

	DFS(start, 1);


	return 0;
}