#include <iostream>
#include <vector>

using namespace std;

const vector<vector<int>> dir =
{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1},
};
const vector<vector<int>> map =
{
	{0, 0, 0, 0 },
	{1, 1, 0, 1 },
	{0, 0, 0, 0 },
	{0, 1, 1, 0 },
};
vector<vector<bool>> visited(4, vector<bool>(4));
int sy, sx;
int ey, ex;

int minPath = INT_MAX;
void DFS(int y, int x, int cost)
{
	visited[y][x] = true;
	cout << y << " " << x << endl;
	if (map[y][x] == 1)
		return;
	else if (minPath < cost)
		return;
	else if (y == ey && x == ex)
	{
		if (minPath > cost)
			minPath = cost;
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

		visited[newY][newX] = false;
	}
}

int main(void)
{
	cin >> sy >> sx >> ey >> ex;

	DFS(sy, sx, 0);

	cout << minPath;

	return 0;
}