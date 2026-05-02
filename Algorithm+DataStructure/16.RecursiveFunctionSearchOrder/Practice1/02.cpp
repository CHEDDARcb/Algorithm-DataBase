#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char strs[3][11];

	for (auto& str : strs)
		cin >> str;

	int sameCount = 0;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = i + 1; j < 3; ++j)
		{
			if (strcmp(strs[i], strs[j]) == 0)
				++sameCount;
		}

		if (sameCount >= 3) break;
	}

	if (sameCount == 3) cout << "WOW";
	else if (sameCount == 2) cout << "GOOD";
	else cout << "BAD";

	return 0;
}