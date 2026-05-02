#include <iostream>

using namespace std;

int main(void)
{
	int arr[5][5] =
	{
		{4, 5, 4, 5, 4},
		{8, 9, 8, 9, 8},
		{1, 2, 1, 2, 1},
		{4, 5, 4, 5, 4},
		{6, 7, 6, 7, 6}
	};

	int y, x;
	for (int i = 0; i < 5; ++i)
	{
		cin >> y >> x;

		++arr[y][x];

		if (arr[y][x] >= 10)
			arr[y][x] = 0;
	}

	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			cout << data;
		}

		cout << endl;
	}

	return 0;
}