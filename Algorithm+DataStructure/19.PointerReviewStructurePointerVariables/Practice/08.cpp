#include <iostream>

using namespace std;

int arr[7] = { 3, 5, 5, 6, 9, 1, 2 };

int main(void)
{
	int r1, r2;

	cin >> r1 >> r2;

	while (r1 < r2)
	{
		int tmp = arr[r1];
		arr[r1] = arr[r2];
		arr[r2] = tmp;

		r1++;
		r2--;
	}

	for (const auto& data : arr)
		cout << data << " ";

	return 0;
}