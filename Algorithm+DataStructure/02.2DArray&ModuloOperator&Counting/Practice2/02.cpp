#include <iostream>

using namespace std;

int main(void)
{
	int arr[6]{};

	for (int i = 0; i < 3; ++i)
	{
		int idx;

		cin >> idx;

		arr[idx] = 1;
	}

	for (const auto& data : arr)
	{
		cout << data << endl;
	}
}