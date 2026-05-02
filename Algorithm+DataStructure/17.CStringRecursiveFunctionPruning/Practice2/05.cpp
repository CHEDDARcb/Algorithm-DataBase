#include <iostream>

using namespace std;

int arr[8];

int main(void)
{
	for (auto& data : arr) cin >> data;

	int p = 0;
	int a = p + 1;
	int b = 7;
	int tmp;

	while (a <= b)
	{
		while (arr[p] >= arr[a]) a++;
		while (arr[p] <= arr[b]) b--;

		if (a > b) break;

		tmp = arr[a];
		arr[a] = arr[b];
		arr[b] = tmp;
	}

	tmp = arr[p];
	arr[p] = arr[b];
	arr[b] = tmp;

	for (const auto& data : arr) cout << data << " ";

	return 0;
}