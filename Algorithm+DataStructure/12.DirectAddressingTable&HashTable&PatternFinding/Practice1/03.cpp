#include <iostream>

using namespace std;

int main()
{
	int arr[3][3];
	int bucket[10]{};

	for (auto& row : arr)
		for (auto& data : row)
			cin >> data;

	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			++bucket[data];
		}
	}

	for (int i = 1; i <= 9; ++i)
	{
		if (!bucket[i])
			cout << i << " ";
	}

	return 0;
}