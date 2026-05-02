#include <iostream>

using namespace std;

int main(void)
{
	char strs[2][6];

	for (auto& str : strs)
		cin >> str;

	int lens[2]{};
	for (int i = 0; i < 2; ++i)
	{
		int len = 0;
		while (strs[i][len] != '\0') { ++len; }
		lens[i] = len;
	}

	for (int k = 0; k < 2; ++k)
	{
		// Bubble
		//for (int i = 0; i < lens[k] - 1; ++i)
		//{
		//	for (int j = 0; j < lens[k] - i - 1; ++j)
		//	{
		//		if (strs[k][j] > strs[k][j + 1])
		//		{
		//			char tmp = strs[k][j];
		//			strs[k][j] = strs[k][j + 1];
		//			strs[k][j + 1] = tmp;
		//		}
		//	}
		//}

		// Select
		for (int p = 0; p < lens[k] - 1; ++p)
		{
			int mIdx = p;
			for (int j = p + 1; j < lens[k]; ++j)
			{
				if (strs[k][mIdx] > strs[k][j])
					mIdx = j;
			}
			char tmp = strs[k][p];
			strs[k][p] = strs[k][mIdx];
			strs[k][mIdx] = tmp;
		}
	}

	char result[12];
	int rIdx = 0;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < lens[i]; ++j)
		{
			result[rIdx++] = strs[i][j];
		}
	}
	result[rIdx] = '\0';

	cout << result;

	return 0;
}