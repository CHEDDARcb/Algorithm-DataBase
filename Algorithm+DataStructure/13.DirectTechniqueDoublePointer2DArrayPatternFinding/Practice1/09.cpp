#include <iostream>

using namespace std;

int rectSum(const int* _base, const int _bWidth,
	const int _iStart, const int _jStart,
	const int _iRange, const int _jRange)
{
	int sum = 0;
	for (int i = 0; i < _iRange; ++i)
	{
		for (int j = 0; j < _jRange; ++j)
		{
			sum += _base[_bWidth * i + j];
		}
	}

	return sum;
}

int main()
{
	int image[4][4]{};

	for (auto& row : image)
		for (auto& data : row)
			cin >> data;

	const int calYRange = 2;
	const int cindXRange = 3;

	int max = INT_MIN;
	int mIIDX = -1;
	int mJIDX = -1;
	for (int i = 0; i < 4 - calYRange + 1; ++i)
	{
		for (int j = 0; j < 4 - cindXRange + 1; ++j)
		{
			int sum = rectSum(image[i], 4, i, j, calYRange, cindXRange);
			if (sum > max)
			{
				max = sum;
				mIIDX = i;
				mJIDX = j;
			}
		}
	}

	cout << "(" << mIIDX << "," << mJIDX << ")";

	return 0;
}