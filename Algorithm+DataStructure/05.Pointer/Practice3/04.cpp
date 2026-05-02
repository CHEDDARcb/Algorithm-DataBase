#include <iostream>

using namespace std;


int main(void)
{
	int input[3];
	int arr[3][4];

	cin >> input[0] >> input[1] >> input[2];

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			arr[i][j] = input[i]++;
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
