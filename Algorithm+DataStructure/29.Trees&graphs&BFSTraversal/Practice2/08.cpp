#include <iostream>
#include <vector>
using namespace std;

vector <vector< char >> map(4, vector<char>(3));
vector<vector<int>> dir =
{
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0}
};
const int SEC = 5;

void InitMap()
{
	for (int i = 0; i < map.size(); ++i)
	{
		for (int j = 0; j < map[i].size(); ++j)
		{
			cin >> map[i][j];
		}
	}
}

bool IsInRange(int y, int x)
{
	if (y < 0 || y >= map.size() ||
		x < 0 || x >= map[y].size())
		return false;
	else
		return true;
}

bool IsOkNext(int y, int x)
{
	if (map[y][x] == '_') return true;
	else return false;
}

void Move(int dirIdx, int ty, int tx)
{
	int newY = ty + dir[dirIdx][0];
	int newX = tx + dir[dirIdx][1];

	if (!IsInRange(newY, newX)) return;
	if (!IsOkNext(newY, newX)) return;

	map[newY][newX] = map[ty][tx];
	map[ty][tx] = '_';
}

void PrintMap()
{
	for (int i = 0; i < map.size(); ++i)
	{
		for (int j = 0; j < map[i].size(); ++j)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
}

void Update(int dirIdx)
{
	for (int i = 0; i < map.size(); ++i)
	{
		for (int j = 0; j < map[i].size(); ++j)
		{
			if (map[i][j] >= 'A' && map[i][j] <= 'Z')
			{
				Move(dirIdx, i, j);
			}
		}
	}
}

int main()
{
	InitMap();
	PrintMap();

	for (int i = 0; i < SEC; ++i)
	{
		int idx = i % dir.size();
		Update(idx);
		PrintMap();
	}

	return 0;
}