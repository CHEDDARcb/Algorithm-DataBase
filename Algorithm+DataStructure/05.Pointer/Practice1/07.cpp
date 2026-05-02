#include <iostream>

using namespace std;

int main(void)
{
	int arr[3][4];
	int num = 1;

	for (int i = 2; i >= 0; --i)
	{
		for (int j = 3; j >= 0; --j)
		{
			arr[i][j] = num++;
		}
	}

	int input;

	cin >> input;

	for (int i = 0; i < 3; ++i)
	{
		arr[i][input] = 0;
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