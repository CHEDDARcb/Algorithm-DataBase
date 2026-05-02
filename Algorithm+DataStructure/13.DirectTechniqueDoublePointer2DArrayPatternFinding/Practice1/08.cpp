#include <iostream>

using namespace std;

int main()
{
	const int direct[8][2] =
	{
		{-1, -1},
		{-1, 0},
		{-1, 1},
		{0, -1},
		{0, 1},
		{1, -1},
		{1, 0},
		{1, 1}
	};
	char base[4][5]{};

	for (auto& row : base)
		for (auto& data : row)
			data = '-';

	for (int k = 0; k < 2; ++k)
	{
		int x, y;
		cin >> y >> x;

		for (int i = 0; i < 8; ++i)
		{
			int boomY = y + direct[i][0];
			int boomX = x + direct[i][1];

			if (boomY >= 0 && boomY <= 3 &&
				boomX >= 0 && boomX <= 4)
			{
				base[boomY][boomX] = '#';
			}
		}
	}

	for (const auto& row : base)
	{
		for (const auto& data : row)
		{
			cout << data << " ";
		}
		cout << endl;
	}

	return 0;
}