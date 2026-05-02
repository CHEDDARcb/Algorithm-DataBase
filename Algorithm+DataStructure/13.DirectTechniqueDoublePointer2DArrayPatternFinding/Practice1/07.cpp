#include <iostream>

using namespace std;

const int map[5][5] =
{
	{3, 3, 5, 3, 1},
	{2, 2, 4, 2, 6},
	{4, 9, 2, 3, 4},
	{1, 1, 1, 1, 1},
	{3, 3, 5, 9, 2}
};
const int direct[4][2] =
{
	{-1, -1},
	{-1, 1},
	{1, -1},
	{1, 1}
};

int Sum(int y, int x)
{
	int sum = 0;
	for (int i = 0; i < 4; ++i)
	{
		int newY = y + direct[i][0];
		int newX = x + direct[i][1];

		if (newY >= 0 && newY <= 4 &&
			newX >= 0 && newX <= 4)
		{
			sum += map[newY][newX];
		}
	}

	return sum;
}

int main()
{
	int max = INT_MIN;
	int mIIDX = -1;
	int mJIDX = -1;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			int sum = Sum(i, j);
			if (max < sum)
			{
				max = sum;
				mIIDX = i;
				mJIDX = j;
			}
		}
	}

	cout << mIIDX << " " << mJIDX;
	return 0;
}