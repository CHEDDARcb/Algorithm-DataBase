#include <iostream>

using namespace std;

int main(void)
{
	int arr[4][4];

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
			if (!data)
				cout << "!" << " ";
			else if (data % 2)
				cout << "@" << " ";
			else
				cout << "#" << " ";
		}
		cout << endl;
	}

	return 0;
}