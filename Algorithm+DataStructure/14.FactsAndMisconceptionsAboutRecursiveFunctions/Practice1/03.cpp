#include <iostream>

using namespace std;

void Movement(int _arr[], int _idx, const int _size)
{
	cout << _arr[_idx] << " ";
	if (_idx >= _size - 1) return;
	Movement(_arr, _idx + 1, _size);
	cout << _arr[_idx] << " ";
}

int main()
{
	int arr[6];

	for (auto& data : arr)
		cin >> data;

	Movement(arr, 0, 6);

	return 0;
}