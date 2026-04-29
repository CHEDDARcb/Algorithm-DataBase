#include <iostream>
#include <vector>

using namespace std;

const vector<vector<int>> dir =
{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1}
};
vector<vector<int>> map(4, vector<int>(4));
vector<vector<bool>> visited(4, vector<bool>(4));
int maxIslandSize = 0;

void DFS(int y, int x, int landSize)
{
	visited[y][x] = true;

	if (map[y][x] == 0)
	{
		if (maxIslandSize < landSize)
			maxIslandSize = landSize;
		return;
	}
	else
		landSize++;

	for (int i = 0; i < dir.size(); ++i)
	{
		int newY = y + dir[i][0];
		int newX = x + dir[i][1];

		if (newY < 0 || newY >= map.size() ||
			newX < 0 || newX >= map[newY].size() ||
			visited[newY][newX])
			continue;

		DFS(newY, newX, landSize);
		visited[newY][newX] = false;
	}
}

int main(void)
{
	for (int i = 0; i < map.size(); ++i)
	{
		for (int j = 0; j < map[i].size(); ++j)
			cin >> map[i][j];
	}

	DFS(0, 0, 0);

	cout << maxIslandSize;

	return 0;
}