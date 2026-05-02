#include <iostream>

using namespace std;

const size_t arrSize = 2;

void ABC(char _arr[], size_t _size)
{
	if (_size < arrSize)
		return;

	for (int i = 0; i < arrSize; ++i)
	{
		cin >> _arr[i];
	}
}

void OUTPUT(char _arr[], size_t _size)
{
	if (_size < arrSize)
		return;

	for (int i = 0; i < arrSize; ++i)
	{
		cout << _arr[i] << " ";
	}
}

int main(void)
{
	char arr[2] = {};

	cout << sizeof(arr) / sizeof(char) << endl;

	ABC(arr, sizeof(arr) / sizeof(char));
	OUTPUT(arr, sizeof(arr) / sizeof(char));

	return 0;
}