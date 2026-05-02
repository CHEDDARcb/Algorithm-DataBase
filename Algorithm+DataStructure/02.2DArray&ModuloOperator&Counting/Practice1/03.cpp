#include <iostream>

using namespace std;

int main(void)
{
	int arr[2][3] =
	{
		{3, 1, 1},
		{2, 3, 2}
	};

	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			cout << data;
		}
	}

	return 0;
}