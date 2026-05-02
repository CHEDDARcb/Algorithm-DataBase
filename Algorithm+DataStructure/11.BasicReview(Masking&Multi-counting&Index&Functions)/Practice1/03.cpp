#include<iostream>

using namespace std;

int main()
{
	int arr[7] = { 5, 9, 4, 6, 1, 5, 8 };
	int idx, target;

	cin >> idx >> target;

	int offset = 0;
	for (int i = idx; i < 7; ++i)
	{
		if (arr[i] == target)
			break;
		++offset;
	}

	cout << offset;
}