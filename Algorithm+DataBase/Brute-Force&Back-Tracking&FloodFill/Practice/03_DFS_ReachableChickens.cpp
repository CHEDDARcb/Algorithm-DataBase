#include<iostream>
#include<vector>

using namespace std;

const vector<vector<int>> dir =
{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0 ,1}
};
vector<vector<int>> map(4, vector<int>(6));
vector<vector<bool>> visited(4, vector<bool>(6, false));
int chikenCnt = 0;

void DFS(int y, int x)
{
	cout << y << ", " << x << endl;
	visited[y][x] = true;

	if (map[y][x] == 2)
		chikenCnt++;

	for (int i = 0; i < dir.size(); ++i)
	{
		int newY = y + dir[i][0];
		int newX = x + dir[i][1];

		if (newY < 0 || newY >= map.size() ||
			newX < 0 || newX >= map[newY].size() ||
			visited[newY][newX] ||
			map[newY][newX] == 1)
			continue;

		DFS(newY, newX);
	}
}

int main(void)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			cin >> map[i][j];
		}
	}

	DFS(0, 0);

	cout << chikenCnt;

	return 0;

}