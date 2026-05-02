#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int dir[4][2] =
	{
		-1, 0,
		1, 0,
		0, 1,
		0, -1
	};
	vector<vector<int>> base(4, vector<int>(4));

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cin >> base[i][j];
		}
	}

	bool isOk = true;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (base[i][j])
			{
				for (int k = 0; k < 4; ++k)
				{
					int targetI = i + dir[k][0];
					int targetJ = j + dir[k][1];

					if (targetI < 0 || targetI > 3 ||
						targetJ < 0 || targetJ > 3)
						continue;

					if (base[targetI][targetJ] == 1)
					{
						isOk = false;
						break;
					}
				}
			}
			if (!isOk) break;
		}
		if (!isOk)break;
	}

	cout << (isOk ? "안전한상태" : "위험한상태");


	return 0;
}