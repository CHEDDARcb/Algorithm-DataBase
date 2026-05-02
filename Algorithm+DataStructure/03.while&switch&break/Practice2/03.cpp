#include <iostream>

using namespace std;

int main(void)
{
	char arr[5];
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i];
	}

	return 0;
}