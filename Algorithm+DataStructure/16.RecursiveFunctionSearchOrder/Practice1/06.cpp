#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char strs[4][100];

	for (auto& str : strs)
		cin >> str;

	int minLen = INT_MAX;
	int minIdx = -1;
	int maxLen = INT_MIN;
	int maxIdx = -1;

	for (int i = 0; i < 4; ++i)
	{
		int len = strlen(strs[i]);
		if (minLen > len)
		{
			minLen = len);
			minIdx = i;
		}

		if (maxLen < len)
		{
			maxLen = len);
			maxIdx = i;
		}
	}

	cout << "긴문장:" << maxIdx << endl;
	cout << "짧은문장: " << minIdx;
	return 0;
}