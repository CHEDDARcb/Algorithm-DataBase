#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> map(4, vector<char>(4, '_'));
int dir[8][2] =
{
	-1, -1,
	-1, 0,
	-1, 1,
	0, 1,
	1, 1,
	1, 0,
	1, -1,
	0, -1
};
struct Pos
{
	int i;
	int j;
};
vector<Pos> homePos(3);

void MakeHome()
{
	for (int k = 0; k < homePos.size(); ++k)
	{
		int i, j;
		cin >> i >> j;
		map[i][j] = '#';
		homePos[k] = Pos{ i, j };
	}
}

void MakeWall()
{
	for (int k = 0; k < homePos.size(); ++k)
	{
		for (int p = 0; p < 8; ++p)
		{
			int wallI = homePos[k].i + dir[p][0];
			int wallJ = homePos[k].j + dir[p][1];

			if (wallI < 0 || wallI > map.size() - 1 ||
				wallJ < 0 || wallJ > map.size() - 1)
				continue;

			map[wallI][wallJ] = '@';
		}
	}
}

int main()
{
	MakeHome();
	MakeWall();

	for (auto& row : map)
	{
		for (auto& data : row)
			cout << data << " ";
		cout << endl;
	}
	return 0;
}