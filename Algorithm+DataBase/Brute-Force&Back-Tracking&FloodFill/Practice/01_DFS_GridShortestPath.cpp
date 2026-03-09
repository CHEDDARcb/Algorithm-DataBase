#include <iostream>
#include <vector>

using namespace std;

const vector<vector<int>> map =
{
	{0, 0, 0, 0},
	{1, 1, 0, 1},
	{0, 0, 0, 0},
	{1, 0, 1, 0}
};
const vector<vector<int>> dir =
{
	{-1, 0},
	{1, 0},
	{0,-1},
	{0, 1},
};
vector<vector<bool>> visited(4, vector<bool>(4, false));
int sy, sx, ey, ex;
int minCost = INT_MAX;

void DFS(int y, int x, int cost)
{
	cout << y << ", " << x << endl;
	visited[y][x] = true;

	if (y == ey && x == ex)
	{
		if (minCost > cost)
		{
			minCost = cost;
		}

		return;
	}

	for (int i = 0; i < dir.size(); ++i)
	{
		int newY = y + dir[i][0];
		int newX = x + dir[i][1];

		if (newY < 0 || newY >= map.size() ||
			newX < 0 || newX >= map[newY].size() ||
			visited[newY][newX] ||
			map[newY][newX] == 1)
			continue;

		DFS(newY, newX, cost + 1);
		visited[y][x] = false;
	}
}

int main(void)
{
	cin >> sy >> sx >> ey >> ex;

	DFS(sy, sx, 0);
	
	cout << minCost;

	return 0;
}