#include <iostream>

using namespace std;

int main(void)
{
	int arr[3][3] =
	{
		{3, 1, 6},
		{7, 8, 4},
		{9, 2, 3},
	};
	int a, b, c;

	cin >> a >> b >> c;

	arr[a][b] = c;

	int max = INT_MIN;
	int min = INT_MAX;

	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			if (data > max)
				max = data;
			if (data < min)
				min = data;
		}
	}

	cout << max + min;

	return 0;
}
