#include <iostream>

using namespace std;


int main(void)
{
	int arr[4][4];

	int num = 1;
	for (int j = 3; j >= 0; --j)
	{
		for (int i = 0; i < 4; ++i)
		{
			arr[i][j] = num++;
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