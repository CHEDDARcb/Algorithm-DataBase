#include <iostream>

using namespace std;

int main()
{
	const int direct4[4][2] =
	{
		{-1, 0},
		{1, 0},
		{0, -1},
		{0, 1}
	};
	const int map[3][3] =
	{
		3, 5, 4,
		1, 1, 2,
		1, 3, 9
	};

	int xpos, ypos;
	cin >> ypos >> xpos;

	int sum = 0;
	for (int i = 0; i < 4; ++i)
	{
		int newYPos = ypos + direct4[i][0];
		int newXPos = xpos + direct4[i][1];

		if (newYPos >= 0 && newYPos <= 4 &&
			newXPos >= 0 && newXPos <= 4)
		{
			sum += map[newYPos][newXPos];
		}
	}

	cout << sum;

	return 0;
}