#include<iostream>

using namespace std;

struct Point
{
	int y;
	int x;
};

int main()
{
	int mask1[4][4] =
	{
		{0, 0, 0, 1},
		{1, 1, 0, 1},
		{1, 0, 0, 1},
		{1, 1, 1, 1}
	};
	int mask2[4][4] =
	{
		{1, 1, 1, 1},
		{1, 0, 1, 1},
		{1, 0, 0, 0},
		{1, 0, 0, 0}
	};

	Point result[16]{};
	int resultIdx = 0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (!(mask1[i][j] | mask2[i][j]))
				result[resultIdx++] = Point{ i, j };
		}
	}

	for (int i = 0; i < resultIdx; ++i)
		cout << "(" << result[i].y << "," << result[i].x << ")" << endl;

	return 0;
}