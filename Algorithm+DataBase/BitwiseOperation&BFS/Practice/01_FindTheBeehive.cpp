#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dir[4][2] =
{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1}
};
vector<vector<int>> map(4, vector<int>(9));
vector<vector<bool>> visited(4, vector<bool>(9, false));
int maxData = INT_MIN;
int maxSize = INT_MIN;

int BFS(int y, int x)
{
	queue<pair<int, int>> que;
	que.push({ y, x });
	visited[y][x] = true;
	int cnt = 0;

	while (!que.empty())
	{
		pair<int, int> cur = que.front();
		que.pop();
		visited[cur.first][cur.second] = true;
		++cnt;

		for (int i = 0; i < sizeof(dir) / sizeof(dir[0]); ++i)
		{
			int newY = cur.first + dir[i][0];
			int newX = cur.second + dir[i][1];

			if (newY < 0 || newY >= map.size() ||
				newX < 0 || newX >= map[newY].size())
				continue;

			if (map[newY][newX] != map[cur.first][cur.second])
				continue;

			if (visited[newY][newX])
				continue;

			que.push({ newY, newX });
			visited[newY][newX] = true;
		}
	}

	return cnt;
}

void Input()
{
	for (int i = 0; i < map.size(); ++i)
	{
		for (int j = 0; j < map[i].size(); ++j)
		{
			cin >> map[i][j];
		}
	}
}

int main(void)
{
	Input();

	for(int i = 0; i < map.size(); ++i)
	{
		for (int j = 0; j < map[i].size(); ++j)
		{
			if(!visited[i][j])
			{
				int cnt = BFS(i, j);

				if (cnt > maxSize)
				{
					maxSize = cnt;
					maxData = map[i][j];
				}
			}
		}
	}

	cout << maxData * maxSize;

	return 0;
}