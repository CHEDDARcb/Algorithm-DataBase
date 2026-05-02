#include <iostream>

using namespace std;

int main(void)
{
	int arr1[5] = { 2, 1, 2, 4, 5 };
	int arr2[3][3] =
	{
		{2, 5, 3},
		{4, 5, 7},
		{8, 7, 2},
	};
	int input;

	cin >> input;

	int cnt = 0;

	for (const auto& data : arr1)
	{
		if (data == input)
			++cnt;
	}

	for (const auto& row : arr2)
	{
		for (const auto& data : row)
		{
			if (data == input)
				++cnt;
		}
	}

	cout << cnt;

	return 0;
}