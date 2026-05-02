#include <iostream>

using namespace std;

int main(void)
{
	char input[16];
	char arr[3][5];
	cin >> input;

	int k = 0;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 5 && input[k] != '\0'; ++j, ++k)
		{
			arr[i][j] = input[k];
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