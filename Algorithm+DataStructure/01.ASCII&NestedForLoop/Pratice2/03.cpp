#include <iostream>

using namespace std;

int main(void)
{
	int arr1[5], arr2[5];

	int num;
	for (int i = 0; i < 5; ++i)
	{
		cin >> num;
		arr1[i] = num;
		arr2[i] = num;
	}

	for (const auto& data : arr1)
	{
		cout << data << " ";
	}
	cout << endl;
	for (const auto& data : arr2)
	{
		cout << data << " ";
	}

	return 0;
}