#include<iostream>

using namespace std;

int main()
{
	int arr[3][3] =
	{
		{3, 5, 9},
		{4, 2, 1},
		{1, 1, 5}
	};
	int mask[3][3];

	for (auto& row : mask)
	{
		for (auto& data : row)
			cin >> data;
	}

	int result = 0;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (mask[i][j])
				result += arr[i][j];
		}
	}

	cout << result;
}