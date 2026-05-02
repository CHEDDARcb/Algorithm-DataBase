#include <iostream>

using namespace std;

template<size_t I, size_t J>
void FillArray(int(&_arr)[I][J], const int _fillNum, const int _fillIdx)
{
	int y = _fillIdx / J;
	int x = _fillIdx % J - 1;

	_arr[y][x] = _fillNum;
}

int main()
{
	int input[4];
	int arr[4][4]{};

	for (auto& data : input)
		cin >> data;

	for (int i = 0; i < 4; ++i)
	{
		FillArray(arr, i + 1, input[i]);
	}

	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			cout << data << " ";
		}
		cout << endl;
	}
	return 0;
}