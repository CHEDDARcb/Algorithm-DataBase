#include <iostream>

using namespace std;

int main(void)
{
	char arr[4][4];
	char c;

	cin >> c;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			arr[i][j] = c;
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