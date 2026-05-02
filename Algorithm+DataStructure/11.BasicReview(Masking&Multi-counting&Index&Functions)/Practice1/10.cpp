#include<iostream>

using namespace std;

int arr[11] = { 3, 4, 1, 1, 2, 6, 8, 7, 8, 9, 10 };

int getSum(int index)
{
	int result = 0;
	for (int i = index; i < min(index + 5, 11); ++i)
	{
		result += arr[i];
	}

	return result;
}

int main()
{
	int startIndex;

	cin >> startIndex;

	cout << getSum(startIndex);

	return 0;
}