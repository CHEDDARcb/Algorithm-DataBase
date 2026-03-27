#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dir[4][2] =
{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1},
};
vector<vector<char>> map(8, vector<char>(9));
vector<vector<int>> group(8, vector<int>(9, 0));

struct Node
{
	int y;
	int x;
	int c;
};

void Groupping(int y, int x, int gn)
{
	queue<Node> que;
	que.push({ y, x, gn });

	while (!que.empty())
	{
		Node cur = que.front();
		que.pop();

		group[cur.y][cur.x] = cur.c;

		for (int i = 0; i < 4; ++i)
		{
			int newY = cur.y + dir[i][0];
			int newX = cur.x + dir[i][1];

			if (newY < 0 || newY >= map.size() ||
				newX < 0 || newX >= map[newY].size())
				continue;

			if (map[newY][newX] == '_')
				continue;

			if (group[newY][newX] != 0)
				continue;

			que.push({ newY, newX, cur.c });
		}
	}
}

int BFS(int y, int x)
{
	int base = group[y][x];
	vector<vector<bool>> visited(8, vector<bool>(9, false));
	queue<Node> que;
	que.push({ y, x, 0 });
	visited[y][x] = true;

	while (!que.empty())
	{
		Node cur = que.front();
		que.pop();

		for (int i = 0; i < 4; ++i)
		{
			int newY = cur.y + dir[i][0];
			int newX = cur.x + dir[i][1];

			if (newY < 0 || newY >= map.size() ||
				newX < 0 || newX >= map[newY].size())
				continue;

			if (visited[newY][newX])
				continue;

			if (group[newY][newX] != 0 && group[newY][newX] != base)
			{
				int n = cur.c;
				return cur.c;
			}

			que.push({ newY, newX, cur.c + 1 });
			visited[newY][newX] = true;
		}
	}

	return -1;
}

int main(void)
{
	for (int i = 0; i < map.size(); ++i)
	{
		for (int j = 0; j < map[i].size(); ++j)
		{
			cin >> map[i][j];
		}
	}

	int groupN = 1;
	for (int i = 0; i < map.size(); ++i)
	{
		for (int j = 0; j < map[i].size(); ++j)
		{
			if(group[i][j] == 0 && map[i][j] == '#')
			{
				Groupping(i, j, groupN);
				groupN++;
			}
		}
	}

	int minCost = INT_MAX;
	const int startGroup = 1;
	for (int i = 0; i < map.size(); ++i)
	{
		for (int j = 0; j < map[i].size(); ++j)
		{
			if (map[i][j] == '#' && group[i][j] == startGroup)
			{
				int cost = BFS(i, j);

				if (cost < minCost)
					minCost = cost;
			}
		}
	}

	cout << minCost;

	return 0;
}