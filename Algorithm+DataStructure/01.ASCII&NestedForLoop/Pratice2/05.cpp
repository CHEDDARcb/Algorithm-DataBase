#include <iostream>

using namespace std;

int main(void)
{
	int arr[3];
	int total = 0;

	for (int i = 0; i < 3; ++i)
	{
		cin >> arr[i];

		total += arr[i];
	}

	for (int i = 0; i < total; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << arr[j] << " ";
		}

		cout << endl;
	}

	return 0;
}