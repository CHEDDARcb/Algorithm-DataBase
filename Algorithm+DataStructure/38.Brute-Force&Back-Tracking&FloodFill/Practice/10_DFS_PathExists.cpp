#include <iostream>

using namespace std;

const int dir[4][2] =
{
	-1, 0,
	1, 0,
	0, -1,
	0, 1,
};
int map[3][3];
bool visited[3][3];

bool can = false;

void DFS(int y, int x)
{
	visited[y][x] = true;

	if (y == 2 && x == 2)
	{
		can = true;
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int newY = y + dir[i][0];
		int newX = x + dir[i][1];

		if (newY < 0 || newY >= 3 ||
			newX < 0 || newY >= 3 ||
			visited[newY][newX] ||
			map[newY][newX] == 1)
			continue;

		DFS(newY, newX);
	}
}

int main(void)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> map[i][j];
		}
	}

	DFS(0, 0);

	cout << (can ? "가능" : "불가능");

	return 0;
}