#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> map(4, vector<int>(4));

vector<vector<int>> dir =
{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1}
};

struct Pos
{
	int data;
	int i;
	int j;
};

queue<Pos> qu;
void Mapping(int data, int i, int j)
{
	qu.push(Pos{ data, i, j });
	map[i][j] = data;

	while (!qu.empty())
	{
		Pos cur = qu.front();
		qu.pop();
		for (int i = 0; i < dir.size(); ++i)
		{
			int nxtI = cur.i + dir[i][0];
			int nxtJ = cur.j + dir[i][1];

			if (nxtI < 0 || nxtI > dir.size() - 1 ||
				nxtJ < 0 || nxtJ > dir.size() - 1 ||
				map[nxtI][nxtJ] > 0) continue;

			map[nxtI][nxtJ] = cur.data + 1;
			qu.push(Pos{ cur.data + 1, nxtI, nxtJ });
		}
	}
}

int main()
{
	int i, j;

	cin >> i >> j;

	Mapping(1, i, j);


	for (auto& row : map)
	{
		for (auto& data : row)
		{
			cout << data << " ";
		}
		cout << endl;
	}


	return 0;
}