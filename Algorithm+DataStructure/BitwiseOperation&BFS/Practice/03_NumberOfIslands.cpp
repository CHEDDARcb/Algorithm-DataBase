#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const vector<vector<int>> dir =
{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1}
};
vector<vector<int>> map(5, vector<int>(8));
vector<vector<bool>> pushed(5, vector<bool>(8, false));

void BFS(int y, int x)
{
	queue<pair<int, int>> que;
	que.push({ y, x });
	pushed[y][x] = true;

	while (!que.empty())
	{
		pair<int, int> cur = que.front();
		que.pop();

		for (int i = 0; i < dir.size(); ++i)
		{
			int newY = cur.first + dir[i][0];
			int newX = cur.second + dir[i][1];

			if (newY < 0 || newY >= map.size() ||
				newX < 0 || newX >= map[newY].size())
				continue;

			if (pushed[newY][newX])
				continue;

			if (map[newY][newX] == 0)
				continue;

			que.push({ newY, newX });
			pushed[newY][newX] = true;
		}
	}
}

int main(void)
{
	for (int i = 0; i < map.size(); ++i)
	{
		for (int j = 0; j < map[i].size(); ++j)
			cin >> map[i][j];
	}

	int cnt = 0;
	for (int i = 0; i < map.size(); ++i)
	{
		for (int j = 0; j < map[i].size(); ++j)
		{
			if (map[i][j] == 1 &&
				!pushed[i][j])
			{
				++cnt;
				BFS(i, j);
			}
		}
	}

	cout << cnt;

	return 0;
}