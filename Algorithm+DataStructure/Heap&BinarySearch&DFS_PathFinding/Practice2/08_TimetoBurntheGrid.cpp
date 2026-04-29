#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> map;
vector<vector<bool>> visited;

struct Pos
{
	int i;
	int j;
	int s;
};
Pos s;
const vector<vector<int>> dir =
{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1}
};

void Input()
{
	int y, x;
	cin >> y >> x;

	map.resize(y, vector<int>(x));
	visited.resize(y, vector<bool>(x, false));

	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			cin >> map[i][j];
		}
	}

	cin >> s.i >> s.j;
	s.s = 0;
}

int BFS()
{
	queue<Pos> que;
	que.push(s);
	int r = 0;

	while (!que.empty())
	{
		Pos cur = que.front();
		visited[cur.i][cur.j] = true;
		que.pop();
		r = cur.s;

		for (int k = 0; k < dir.size(); ++k)
		{
			int newI = cur.i + dir[k][0];
			int newJ = cur.j + dir[k][1];

			if ((newI < 0 || newI >= map.size()) ||
				(newJ < 0 || newJ >= map[newI].size()) ||
				(visited[newI][newJ]) ||
				(map[newI][newJ] == 1))
				continue;

			que.push(Pos{ newI, newJ, r + 1 });
			visited[newI][newJ] = true;
		}
	}

	return r;
}

int main(void)
{
	Input();

	int result = BFS();

	cout << result;

	return 0;
}