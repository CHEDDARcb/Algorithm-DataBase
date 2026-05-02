#include <iostream>

using namespace std;

int main()
{
	const int log[3][4] =
	{
		{65000, 35, 42, 70},
		{70, 35, 65000, 1300},
		{65000, 30000, 38, 42},
	};
	int bucket[65535 + 1]{};

	int max = 0;
	int maxIdx = -1;
	for (const auto& row : log)
	{
		for (const auto& data : row)
		{
			++bucket[data];
			if (max < bucket[data])
			{
				max = bucket[data];
				maxIdx = data;
			}
		}
	}

	cout << maxIdx;

	return 0;