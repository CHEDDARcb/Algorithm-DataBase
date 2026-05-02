#include <iostream>
#include <cmath>

using namespace std;

int RowSum(const int* _base, const int _row, const int _col)
{
	int sum = 0;
	for (int i = 0; i < _row; ++i)
	{
		sum += _base[i * _col];
	}

	return sum;
}

int main()
{
	const int base[3][4] =
	{
		3, 4, 1, 5,
		3, 4, 1, 3,
		5, 2, 3, 6
	};
	int sum[4];
	int idx;

	cin >> idx;

	for (int i = 0; i < 4; ++i)
	{
		sum[i] = RowSum(&base[0][i], 3, 4);
	}

	cout << sum[idx];

	return 0;
}