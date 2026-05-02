#include <iostream>

using namespace std;

int main(void)
{
	int arr[3][2];

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			int input;
			cin >> input;

			arr[i][j] = input + 2;
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