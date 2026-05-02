#include <iostream>

using namespace std;

template<size_t I, size_t J>
int AreaSum(const int* _map, const int _mapCol, const bool(&_bitArray)[I][J])
{
	int sum = 0;
	for (size_t i = 0; i < I; ++i)
	{
		for (size_t j = 0; j < J; ++j)
		{
			if (_bitArray[i][j])
			{
				sum += _map[i * _mapCol + j];
			}
		}
	}

	return sum;
}

int main()
{
	const int map[3][3] =
	{
		3, 5, 1,
		3, 8, 1,
		1, 1, 5
	};
	bool bitArray[2][2]{};

	for (auto& row : bitArray)
	{
		for (auto& data : row)
		{
			cin >> data;
		}
	}

	int mapRow = sizeof(map) / sizeof(map[0]);
	int mapCol = sizeof(map[0]) / sizeof(int);
	int bitRow = sizeof(bitArray) / sizeof(bitArray[0]);
	int bitCol = sizeof(bitArray[0]) / sizeof(bool);

	int max = INT_MIN;
	int miIdx = -1;
	int mjIdx = -1;
	int sum;
	for (int i = 0; i < mapRow - bitRow + 1; ++i)
	{
		for (int j = 0; j < mapCol - bitCol + 1; ++j)
		{
			sum = AreaSum(&map[i][j], mapCol, bitArray);
			if (max < sum)
			{
				max = sum;
				miIdx = i;
				mjIdx = j;
			}
		}
	}

	cout << "(" << miIdx << "," << mjIdx << ")";

	return 0;
}