#include <iostream>

using namespace std;

int main(void)
{
	int arr[3][3]{};
	int input;

	cin >> input;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 2 - i; j < 3; ++j)
		{
			arr[i][j] = input++;
		}
	}

	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			cout << data;
		}
		cout << endl;
	}

	return 0;
}