#include <iostream>

using namespace std;

int main(void)
{
	int arr[2][3];

	for (auto& row : arr)
	{
		for (auto& data : row)
		{
			cin >> data;
		}
	}

	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			if (data == 0)
				cout << "#";
			else
				cout << data;
		}
		cout << endl;
	}
	return 0;
}