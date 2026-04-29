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
const int SHIRIMP = 1;
const int SQUID = 2;
const int MAX_SH_Dist = 3;
const int MAX_SQ_Dist = 4;
vector<vector<int>> map(7, vector<int>(7));
vector<vector<bool>> visited(7, vector<bool>(7));
struct Node
{
	int y;
	int x;
	int sf;
	int dist;
};

bool IsOverDist(int target, int dist)
{
	if (target == SHIRIMP)
	{
		if (dist >= MAX_SH_Dist)
			return true;
	}
	else
	{
		if (dist >= MAX_SQ_Dist)
			return true;
	}

	return false;
}

bool BFS(int y, int x)
{
	queue<Node> que;
	que.push({ y, x, map[y][x], 0 });
	visited[y][x] = true;
	int targetSF = map[y][x];

	while (!que.empty())
	{
		Node cur = que.front();
		que.pop();

		if (IsOverDist(targetSF, cur.dist))
			continue;

		if ((cur.y != y || cur.x != x) &&
			map[cur.y][cur.x] == targetSF)
			return false;

		for (int i = 0; i < 4; ++i)
		{
			int newY = cur.y + dir[i][0];
			int newX = cur.x + dir[i][1];

			if (newY < 0 || newY >= map.size() ||
				newX < 0 || newX >= map[newY].size())
				continue;

			if (visited[newY][newX])
				continue;

			que.push({ newY, newX, map[newY][newX], cur.dist + 1 });
			visited[newY][newX] = true;
		}

	}

	return true;
}

int main(void)
{
	for (int i = 0; i < map.size(); ++i)
	{
		string input;
		cin >> input;
		for (int j = 0; j < map[i].size(); ++j)
		{
			map[i][j] = input[j] - '0';
		}
	}

	bool isPass = true;
	for (int i = 0; i < map.size(); ++i)
	{
		for (int j = 0; j < map[i].size(); ++j)
		{
			if(map[i][j] == SHIRIMP || map[i][j] == SQUID)
			{
				if (!(isPass = BFS(i, j)))
					break;

				visited.assign(7, vector<bool>(7, false));
			}
		}

		if (!isPass)
			break;
	}

	cout << (isPass ? "pass" : "fail");

	return 0;
}