#include <iostream>

using namespace std;

int AreaSum(const int* _base, const int _bCol,
	const int _pRow, const int pCol)
{
	int sum = 0;
	for (int i = 0; i < _pRow; ++i)
	{
		for (int j = 0; j < pCol; ++j)
		{
			sum += _base[i * _bCol + j];
		}
	}

	return sum;
}

int main()
{
	const int arrRow = 4;
	const int arrCol = 5;
	const int arr[arrRow][arrCol] =
	{
		3, 5, 4, 2, 5,
		3, 3, 3, 2, 1,
		3, 2, 6, 7, 8,
		9, 1, 1, 3, 2
	};
	int patRow;
	int patCol;
	cin >> patRow >> patCol;

	int max = INT_MIN;
	int mIIdx = -1;
	int mJIdx = -1;
	int sum;
	for (int i = 0; i < arrRow - patRow + 1; ++i)
	{
		for (int j = 0; j < arrCol - patCol + 1; ++j)
		{
			sum = AreaSum(&arr[i][j], arrCol, patRow, patCol);
			if (max < sum)
			{
				max = sum;
				mIIdx = i;
				mJIdx = j;
			}
		}
	}

	cout << "(" << mIIdx << "," << mJIdx << ")";

	return 0;
}