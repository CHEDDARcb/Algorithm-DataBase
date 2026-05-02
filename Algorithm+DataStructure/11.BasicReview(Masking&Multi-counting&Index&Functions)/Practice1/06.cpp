#include<iostream>

using namespace std;

int main()
{
	bool mask[2][5] =
	{
		{0, 0, 1, 0, 0},
		{0, 0, 1, 1, 1}
	};
	int base[2][5] =
	{
		{3, 5, 4, 1, 1},
		{3, 5, 2, 5, 6}
	};
	int target;
	cin >> target;

	bool isIn = false;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (mask[i][j])
			{
				if (base[i][j] == target)
				{
					isIn = true;
					break;
				}
			}

			if (isIn)
				break;
		}

	}

	if (isIn)
		cout << "존재";
	else
		cout << target << "없음" << endl;

	return 0;
}