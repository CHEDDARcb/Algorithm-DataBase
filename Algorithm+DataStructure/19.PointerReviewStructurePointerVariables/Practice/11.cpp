#include <iostream>

using namespace std;

const int base[4][4] =
{
	-1, -1, -1, -1,
	-1, 1, 1, -1,
	2, 2, 3, -1,
	3, 3, 3, 1
};
bool checkedCol[4]{};

bool IsSafe(int y, int x)
{
	int min = base[y][x];
	for (int i = y + 1; i < 4; ++i)
	{
		if (min > base[i][x])
			return false;
	}
	return true;
}

int main(void)
{
	bool isSafe = true;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (checkedCol[j])
				continue;

			if (base[i][j] > -1)
			{
				isSafe = IsSafe(i, j);
				checkedCol[j] = true;
			}

			if (!isSafe) break;
		}

		if (!isSafe) break;
	}

	if (isSafe) cout << "안전한성" << endl;
	else cout << "안전하지않은성" << endl;

	return 0;
}