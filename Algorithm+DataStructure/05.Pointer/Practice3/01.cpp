#include <iostream>

using namespace std;

int main(void)
{
	int arr[4][4] =
	{
		{2, 10, 18, 26},
		{4, 12, 20, 28},
		{6, 14, 22, 30},
		{8, 16, 24, 32},
	};

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
