#include<iostream>

using namespace std;

int main()
{
	int base[3][3] =
	{
		{3, 7, 4},
		{2, 2, 4},
		{2, 2, 5}
	};
	int target[3];

	cin >> target[0] >> target[1] >> target[2];

	int maxEx = INT_MIN;
	int maxIdx = -1;
	for (int k = 0; k < 3; ++k)
	{
		int targetCnt = 0;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (target[k] == base[i][j])
					++targetCnt;
			}
		}

		if (targetCnt > maxEx)
		{
			maxEx = targetCnt;
			maxIdx = k;
		}
	}

	cout << target[maxIdx];

	return 0;
}