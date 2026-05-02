#include <iostream>

using namespace std;

void RecurPrint(const int _arr[], int _idx)
{
	cout << _arr[_idx] << " ";
	if (_idx <= 0) return;
	RecurPrint(_arr, _idx - 1);
	cout << _arr[_idx] << " ";
}

int main()
{
	int arr[8] = { 3, 7, 4, 1, 9, 4, 6, 2 };
	int indx;

	cin >> indx;

	RecurPrint(arr, indx);

	return 0;
}