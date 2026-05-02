#include<iostream>

using namespace std;

int FindMinIdx(const int _arr[])
{
	int min = INT_MAX;
	int minIdx = -1;
	for (int i = 0; i < 6; ++i)
	{
		if (_arr[i] && min > _arr[i])
		{
			min = _arr[i];
			minIdx = i;
		}
	}

	return minIdx;
}

int main()
{
	const int masking[6] = { 1, 0, 1, 0, 1, 0 };
	int arr[6];

	for (auto& data : arr)
		cin >> data;

	for (int i = 0; i < 6; ++i)
		if (!masking[i])
			arr[i] = 0;

	int minIdx = FindMinIdx(arr);
	cout << "arr[" << minIdx << "]=" << arr[minIdx];

	return 0;
}