#include <iostream>

using namespace std;

template<size_t I, size_t J>
bool FindPattern(const char* _map, const int _mapCol, const char(&_pattern)[I][J])
{
	for (size_t i = 0; i < I; ++i)
	{
		for (size_t j = 0; j < J; ++j)
		{
			if (_map[i * _mapCol + j] != _pattern[i][j])
				return false;
		}
	}

	return true;
}

int main()
{
	char map[3][4] =
	{
		{'A', 'B', 'G', 'K'},
		{'T', 'T', 'A', 'B'},
		{'A', 'C', 'C', 'D'}
	};
	char pattern[2][2];

	for (auto& row : pattern)
	{
		for (auto& data : row)
		{
			cin >> data;
		}
	}

	int mapRow = sizeof(map) / sizeof(map[0]);
	int mapCol = sizeof(map[0]) / sizeof(char);
	int patternRow = sizeof(pattern) / sizeof(pattern[0]);
	int patternCol = sizeof(pattern[0]) / sizeof(char);

	int patternCnt = 0;
	for (int i = 0; i < mapRow - patternRow + 1; ++i)
	{
		for (int j = 0; j < mapCol - patternCol + 1; ++j)
		{
			if (FindPattern(&map[i][j], mapCol, pattern))
			{
				++patternCnt;
			}
		}
	}

	if (patternCnt)
		cout << "발견(" << patternCnt << "개)";
	else
		cout << "미발견";

	return 0;
}