#include <iostream>

using namespace std;

int main(void)
{
	int arr[7];

	for (auto& data : arr)
	{
		cin >> data;
	}

	int mx = INT_MIN;
	int mn = INT_MAX;

	for (const auto& data : arr)
	{
		if (data > mx)
			mx = data;
		if (data < mn)
			mn = data;
	}

	cout << "MAX=" << mx << endl;
	cout << "MIN=" << mn << endl;


	return 0;
}