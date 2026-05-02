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
vector<vector<char>> map(3, vector<char>(5));
vector<vector<bool>> pushed(3, vector<bool>(5, false));
struct Pos
{
	int y;
	int x;
	int dist;
};

Pos BFS(int y, int x, char target)
{
	queue<Pos> que;
	que.push(Pos{ y, x, 0 });
	pushed[y][x] = true;

	while (!que.empty())
	{
		Pos cur = que.front();
		que.pop();

		if (map[cur.y][cur.x] == target)
			return cur;

		for (int i = 0; i < dir.size(); ++i)
		{
			int newY = cur.y + dir[i][0];
			int newX = cur.x + dir[i][1];

			if (newY < 0 || newY >= map.size() ||
				newX < 0 || newX >= map[newY].size() ||
				pushed[newY][newX] ||
				map[newY][newX] == '#')
				continue;

			que.push(Pos{ newY, newX, cur.dist + 1 });
			pushed[newY][newX] = true;
		}
	}

	return Pos{ -1, -1, -1 };
}

int main(void)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 5; ++j)
			cin >> map[i][j];
	}

	Pos t1 = BFS(0, 0, '1');
	int cost1 = t1.dist;
	pushed.assign(3, vector<bool>(5, false));

	Pos t2 = BFS(t1.y, t1.x, '2');
	int cost2 = t2.dist;
	pushed.assign(3, vector<bool>(5, false));

	Pos t3 = BFS(t2.y, t2.x, '3');
	int cost3 = t3.dist;
	pushed.assign(3, vector<bool>(5, false));

	Pos t4 = BFS(t3.y, t3.x, '4');
	int cost4 = t4.dist;
	pushed.assign(3, vector<bool>(5, false));

	int result = cost1 + cost2 + cost3 + cost4;
	cout << result << "ȸ";

	return 0;

}