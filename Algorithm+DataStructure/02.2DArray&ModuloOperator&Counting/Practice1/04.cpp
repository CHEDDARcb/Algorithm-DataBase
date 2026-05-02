#include <iostream>

using namespace std;

int main(void)
{
	int arr[5];

	for (int i = 0; i < 5; ++i)
	{
		cin >> arr[i];
	}

	int count = 0;
	for (const auto& data : arr)
	{
		if (data >= 3 && data <= 7)
			++count;
	}

	cout << count;

	return 0;
}