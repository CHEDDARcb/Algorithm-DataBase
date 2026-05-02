#include <iostream>

using namespace std;

int main(void)
{
	int arr[3][3] =
	{
		{3, 5, 14},
		{2, 3, 9},
		{6, 2, 7}
	};
	int input;

	cin >> input;

	int cnt = 0;
	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			if (data % input == 0)
			{
				++cnt;
			}
		}
	}

	cout << cnt;

	return 0;
}