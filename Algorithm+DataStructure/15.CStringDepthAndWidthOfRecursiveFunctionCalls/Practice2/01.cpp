#include <iostream>
#include <cmath>

using namespace std;

struct IDX
{
	int y;
	int x;
};

template <size_t I, size_t J>
IDX FindTarget(const char(&_base)[I][J], const char _target)
{
	for (size_t i = 0; i < I; ++i)
	{
		for (size_t j = 0; j < J; ++j)
		{
			if (_target == _base[i][j])
			{

				return IDX(i, j);
			}
		}
	}
}

int main()
{
	char base[4][3];

	for (auto& row : base)
		for (auto& data : row)
			cin >> data;

	IDX aIdx = FindTarget(base, 'A');
	IDX bIdx = FindTarget(base, 'B');

	int result = 0;
	result += abs(aIdx.y - bIdx.y);
	result += abs(aIdx.x - bIdx.x);

	cout << result;

	return 0;
}