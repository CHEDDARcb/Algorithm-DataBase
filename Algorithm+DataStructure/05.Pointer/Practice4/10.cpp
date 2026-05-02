#include <iostream>

using namespace std;

int main(void)
{
	int arr1[2][3];

	for (int i = 1; i >= 0; --i)
	{
		for (int j = 2; j >= 0; --j)
		{
			cin >> arr1[i][j];
		}
	}

	int arr2[6];
	int idx = 0;

	for (const auto& row : arr1)
	{
		for (const auto& data : row)
		{
			arr2[idx++] = data;
		}
	}

	int tmp = arr2[0];
	arr2[0] = arr2[5];
	arr2[5] = tmp;

	for (const auto& data : arr2)
	{
		cout << data << " ";
	}

	return 0;
}
