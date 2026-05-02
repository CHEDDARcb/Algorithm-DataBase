#include <iostream>

using namespace std;

int main(void)
{
	int arr[6][3];
	int data = 10;

	for (int j = 0; j < 3; ++j)
	{
		for (int i = 0; i < 6; ++i)
		{
			arr[i][j] = data++;
		}
	}

	int a, b;

	cin >> a >> b;

	for (int i = a; i <= b; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			arr[i][j] = 7;
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