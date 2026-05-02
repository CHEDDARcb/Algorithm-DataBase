#include <iostream>

using namespace std;

int main(void)
{
	int arr[6] = { 3, 4, 2, 5, 7, 9 };
	int a, b;

	cin >> a >> b;

	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;

	for (const auto& data : arr)
	{
		cout << data << " ";
	}

	return 0;
}