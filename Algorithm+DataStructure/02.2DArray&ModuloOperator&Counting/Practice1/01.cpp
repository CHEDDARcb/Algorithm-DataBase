#include <iostream>

using namespace std;

int main(void)
{
	int arr1[5] = { 3, 5, 2, 4, 1 };
	int arr2[3][2] = {
		{9, 8},
		{7, 1},
		{3, 4}
	};
	int num;

	cin >> num;

	if (num % 2)
	{
		for (const auto& data : arr1)
			cout << data << endl;
	}
	else
	{
		for (const auto& arr : arr2)
		{
			for (const auto& data : arr)
			{
				cout << data;
			}
			cout << endl;
		}
	}

	return 0;
}