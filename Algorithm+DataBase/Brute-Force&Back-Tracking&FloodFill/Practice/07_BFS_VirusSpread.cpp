#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const vector<vector<int>> dir =
{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1},
};
vector<vector<bool>> pushed(3, vector<bool>(3));
vector<vector<int>> map(3, vector<int>(3));
struct Pos
{
	int y;
	int x;
	int str;
};
queue<Pos> que;

void BFS()
{
	while (!que.empty())
	{
		Pos cur = que.front();
		que.pop();

		map[cur.y][cur.x] = cur.str;

		for (int i = 0; i < dir.size(); ++i)
		{
			int newY = cur.y + dir[i][0];
			int newX = cur.x + dir[i][1];

			if (newY < 0 || newY >= map.size() ||
				newX < 0 || newX >= map[newY].size() ||
				pushed[newY][newX])
				continue;

			que.push(Pos{ newY, newX, cur.str + 1 });
			pushed[newY][newX] = true;
		}
	}
}

int main(void)
{
	int y1, x1, y2, x2;
	cin >> y1 >> x1 >> y2 >> x2;

	que.push(Pos{ y1, x1, 1 });
	que.push(Pos{ y2, x2, 1 });
	pushed[y1][x1] = true;
	pushed[y2][x2] = true;

	BFS();

	for (const auto& row : map)
	{
		for (const auto& data : row)
		{
			cout << data;
		}
		cout << endl;
	}

	return 0;
}