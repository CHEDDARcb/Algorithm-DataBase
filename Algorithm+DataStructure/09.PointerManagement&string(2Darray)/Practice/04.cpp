#include <iostream>

using namespace std;

int main(void)
{
	char strs[2][7];

	for (auto& str : strs)
		cin >> str;

	int lens[2]{};

	for (int i = 0; i < 2; ++i)
	{
		int len = 0;
		while (strs[i][len] != '\0') { ++len; }
		lens[i] = len;
	}

	if (lens[0] - lens[1] != 0)
	{
		cout << "다름";
	}
	else
	{
		for (int i = 0; i < lens[0]; ++i)
		{
			if (strs[0][i] != strs[1][i])
			{
				cout << "다름";
				return 0;
			}
		}
		cout << "같음";
	}

	return 0;
}