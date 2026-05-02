#include <iostream>
#include <vector>

using namespace std;

int main()
{
	char strs[4][10]{};

	for (int i = 0; i < 4; ++i)
	{
		cin >> strs[i];
	}

	int min = INT_MAX;
	int minIdx = -1;
	int max = INT_MIN;
	int maxIdx = -1;
	for (int i = 0; i < 4; ++i)
	{
		int len = 0;
		while (strs[i][len] != '\0') len++;

		if (min > len)
		{
			min = len;
			minIdx = i;
		}
		if (max < len)
		{
			max = len;
			maxIdx = i;
		}
	}

	for (int i = 0; i < min; ++i)
	{
		strs[minIdx][i] += 32;
	}
	for (int i = 0; i < max; ++i)
	{
		strs[maxIdx][i] += 32;
	}

	for (auto& str : strs)
		cout << str << endl;

	return 0;
}