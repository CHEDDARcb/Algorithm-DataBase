#include <iostream>

using namespace std;

int main(void)
{
	int arr[6];

	for (int i = 0; i < 6; ++i)
	{
		cin >> arr[i];
	}

	for (int p = 0; p < 5; ++p)
	{
		int max = p;
		for (int i = p + 1; i < 6; ++i)
		{
			if (arr[max] < arr[i])
				max = i;
		}

		int tmp = arr[max];
		arr[max] = arr[p];
		arr[p] = tmp;
	}

	for (const auto& data : arr)
	{
		cout << data;
	}

	return 0;
}