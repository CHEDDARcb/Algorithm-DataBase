#include <iostream>

using namespace std;

int main(void)
{
	int arr[5][5]{};
	int input;

	cin >> input;

	for (int j = 0; j < 5; ++j)
	{
		arr[0][j] = input;
	}
	for (int j = 0; j < 5; ++j)
	{
		arr[4][j] = input;
	}

	for (int i = 1; i < 4; ++i)
	{
		arr[i][0] = input;
	}
	for (int i = 1; i < 4; ++i)
	{
		arr[i][4] = input;
	}

	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			if (!data)
				cout << '_';
			else
				cout << data;
		}
		cout << endl;
	}

	return 0;
}
