#include <iostream>

using namespace std;

int main(void)
{
	int arr[4][4] =
	{
		{1, 3, 6, 2},
		{4, 2, 4, 5},
		{6, 3, 7, 3},
		{1, 5, 4, 6}
	};
	int input;
	int select[16];

	cin >> input;

	int selIDX = 0;

	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			if (data > input)
				select[selIDX++] = data;
		}
	}

	for (int i = 0; i < selIDX; ++i)
	{
		cout << select[i] << " ";
	}
	return 0;
}