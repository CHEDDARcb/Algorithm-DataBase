#include <iostream>

using namespace std;

bool isPattern(const int _base[], const int _startIdx,
	const int pattern[], const int _pSize)
{
	for (int i = 0; i < _pSize; ++i)
	{
		if (_base[_startIdx + i] != pattern[i])
			return false;
	}

	return true;
}

int main()
{
	const int apart[5][3] =
	{
		{15, 18, 17},
		{4, 6, 9},
		{10, 1, 3},
		{7, 8, 9},
		{15, 2, 6},
	};
	int family[3];

	for (auto& data : family)
		cin >> data;

	int apartHeight = sizeof(apart) / sizeof(apart[0]);
	int apartWidth = sizeof(apart[0]) / sizeof(int);
	int familySize = sizeof(family) / sizeof(int);

	for (int i = 0; i < apartHeight; ++i)
	{
		for (int j = 0; j < apartWidth - familySize + 1; ++j)
		{
			if (isPattern(apart[i], j, family, familySize))
				cout << apartHeight - i << "Ãþ" << endl;
		}
	}

	return 0;
}