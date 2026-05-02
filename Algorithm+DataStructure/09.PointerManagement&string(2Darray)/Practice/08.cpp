#include <iostream>

using namespace std;

int main(void)
{
	char strs[4][7];

	for (auto& str : strs)
		cin >> str;

	int lens[4]{};
	for (int i = 0; i < 4; ++i)
	{
		int len = 0;
		while (strs[i][len] != '\0') { ++len; }
		lens[i] = len;
	}

	//Bubble
	// for (int i = 0; i < 3; ++i)
	// {
	// 	for (int j = 0; j < 3 - i; ++j)
	// 	{
	// 		if (lens[j] > lens[j + 1])
	// 		{
	// 			int tmp = lens[j];
	// 			lens[j] = lens[j + 1];
	// 			lens[j + 1] = tmp;
	// 		}
	// 	}
	// }

	//Select
	for (int p = 0; p < 3; ++p)
	{
		int mIdx = p;
		for (int j = p + 1; j < 4; ++j)
		{
			if (lens[mIdx] > lens[j])
				mIdx = j;
		}
		int tmp = lens[p];
		lens[p] = lens[mIdx];
		lens[mIdx] = tmp;
	}

	for (const auto& len : lens)
		cout << len << " ";

	return 0;
}