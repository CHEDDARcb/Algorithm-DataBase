#include <iostream>

using namespace std;

int main(void)
{
	int arr[3][3];
	int input;

	cin >> input;

	int num = 1;
	if (input % 5 == 1)
	{
		for (int x = 2; x >= 0; --x)
		{
			for (int y = 2; y >= 0; --y)
			{
				arr[y][x] = num++;
			}
		}
	}
	else if (input % 5 == 2)
	{
		for (int y = 2; y >= 0; --y)
		{
			for (int x = 0; x < 3; ++x)
			{
				arr[y][x] = num++;
			}
		}
	}
	else
	{
		num = 10;

		for (int x = 0; x < 3; ++x)
		{
			for (int y = 0; y < 3; ++y)
			{
				arr[y][x] = num++;
			}
		}
	}

	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			cout << data << " ";
		}
		cout << endl;
	}

	return 0;
}