#include <iostream>

using namespace std;

int main(void)
{
	int arr[4][4] =
	{
		{3, 4, 1, 6},
		{3, 5, 3, 6},
		{},
		{5, 4, 6, 0}
	};

	for (int j = 0; j < 4; ++j)
	{
		cin >> arr[2][j];
	}

	int max = INT_MIN;
	int min = INT_MAX;
	int maxiIdx = -1;
	int maxjIdx = -1;
	int miniIdx = -1;
	int minjIdx = -1;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (max < arr[i][j])
			{
				max = arr[i][j];
				maxiIdx = i;
				maxjIdx = j;
			}
			if (min > arr[i][j])
			{
				min = arr[i][j];
				miniIdx = i;
				minjIdx = j;
			}
		}
	}

	cout << "MAX=" << max << "(" << maxiIdx << "," << maxjIdx << ")" << endl;
	cout << "MIN=" << min << "(" << miniIdx << "," << minjIdx << ")" << endl;

	return 0;
}