#include <iostream>

using namespace std;

int main(void)
{
	int arr[5][5];

	int num = 1;
	for (int j = 4; j >= 0; --j)
	{
		for (int i = 0; i < 5; ++i)
		{
			arr[i][j] = num++;
		}
	}

	int input;

	cin >> input;

	for (int j = 0; j < 5; ++j)
	{
		arr[input][j] = input;
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
