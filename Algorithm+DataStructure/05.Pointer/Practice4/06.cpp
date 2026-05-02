#include <iostream>

using namespace std;

void CompareGo(int arr1[], int arr2[])
{
	for (int i = 0; i < 5; ++i)
	{
		if (arr1[i] != arr2[i])
		{
			cout << "두배열은같지않음";
			return;
		}
	}

	cout << "두배열은완전같음";
	return;
}

int main(void)
{
	int arr[5] = { 3, 5, 1, 2, 7 };
	int input[5];

	for (auto& data : input)
	{
		cin >> data;
	}

	CompareGo(arr, input);

	return 0;
}