#include<iostream>

using namespace std;

int main()
{
	const int base[3][3] =
	{
		{3, 1, 9},
		{7, 2, 1},
		{1, 0, 8}
	};
	int mask[3][3];

	for (auto& row : mask)
		for (auto& data : row)
			cin >> data;

	bool isIn = false;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (mask[i][j])
			{
				if (base[i][j] >= 3 && base[i][j] <= 5)
				{
					isIn = true;
					break;
				}
			}
		}

		if (isIn)
			break;
	}

	if (isIn)
		cout << "발견";
	else
		cout << "미발견";

	return 0;
}