#include <iostream>

using namespace std;

int main()
{
	int arr[7];

	for (auto& data : arr)
		cin >> data;

	for (int i = 3; i < 7; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			cout << arr[j] << " ";
		}
		cout << endl;
	}
	return 0;
}