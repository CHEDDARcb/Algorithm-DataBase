#include<iostream>

using namespace std;

bool FindColor(const int _map[], const size_t _mapSize, const int _target)
{
	for (int i = 0; i < _mapSize; ++i)
	{
		if (*(_map + i) == _target)
			return true;
	}

	return false;
}

int main()
{
	const int map[2][3] =
	{
		{3, 55, 42},
		{-5, -9, -10}
	};
	int pix[2][2];

	for (auto& row : pix)
		for (auto& data : row)
			cin >> data;

	for (int k = 0; k < sizeof(pix) / sizeof(pix[0]); ++k)
	{
		for (int q = 0; q < sizeof(pix[0]) / sizeof(int); ++q)
		{
			int failsCount = 0;
			for (int i = 0; i < sizeof(map) / sizeof(map[0]); ++i)
			{
				if (!FindColor(map[i], sizeof(map[i]) / sizeof(int), pix[k][q]))
					++failsCount;
			}
			if (failsCount == sizeof(map) / sizeof(map[0]))
				cout << "N ";
			else
				cout << "Y ";
		}
		cout << endl;
	}

	return 0;
}