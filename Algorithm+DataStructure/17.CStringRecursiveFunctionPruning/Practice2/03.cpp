#include <iostream>

using namespace std;

int arr[4][4];

int main(void)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
			cin >> arr[i][j];
	}

	for (int i = 0; i < 3; ++i)
	{
		int sum = 0;
		int j;
		for (j = 0; j < 3; ++j)
		{
			sum += arr[i][j];
		}
		arr[i][j] = sum;
	}

	for (int j = 0; j < 3; ++j)
	{
		int sum = 0;
		int i;
		for (i = 0; i < 3; ++i)
		{
			sum += arr[i][j];
		}

		arr[i][j] = sum;
	}

	int k;
	int sum = 0;
	for (k = 0; k < 3; ++k)
	{
		sum += arr[k][k];
	}
	arr[k][k] = sum;

	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			cout << data << " ";
		}
		cout << endl;
	}
}