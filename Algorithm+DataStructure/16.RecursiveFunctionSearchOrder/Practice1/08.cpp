#include <iostream>

using namespace std;

int main()
{
	int arr[3][2][2] =
	{
		{2, 4,
		1, 5},

		{2, 3,
		3, 6},

		{7, 3,
		1, 5}
	};
	int n;

	cin >> n;

	int max = INT_MIN;
	int min = INT_MAX;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if (max < arr[n][i][j]) max = arr[n][i][j];
			if (min > arr[n][i][j]) min = arr[n][i][j];
		}
	}

	cout << "MAX = " << max << endl;
	cout << "MIN = " << min;

	return 0;
}