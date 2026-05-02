#include <iostream>

using namespace std;

int main(void)
{
	int arr[6] = { 5, 4, 1, 2, 7, 8 };
	int n;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = sizeof(arr) / sizeof(int) - 1; j >= 0; --j)
		{
			cout << arr[j] << " ";
		}
		cout << endl;
	}

	return 0;
}