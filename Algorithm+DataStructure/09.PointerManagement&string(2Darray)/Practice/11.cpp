#include <iostream>

using namespace std;

int main(void)
{
	char strs[5][11];

	for (auto& str : strs)
		cin >> str;

	int lens[5];
	for (int i = 0; i < 5; ++i)
	{
		int len = 0;
		while (strs[i][len] != '\0') { ++len; }
		lens[i] = len;
	}

	int mIdx = 0;
	for (int i = 1; i < 5; ++i)
	{
		if (lens[mIdx] < lens[i])
			mIdx = i;
	}

	cout << strs[mIdx];

	return 0;
}