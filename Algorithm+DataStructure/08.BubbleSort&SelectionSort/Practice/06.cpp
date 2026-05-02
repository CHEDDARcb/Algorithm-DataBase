#include <iostream>

using namespace std;

int main(void)
{
	const char strs[3][100] =
	{
		"BBQWORLD",
		"KFCAPPLE",
		"LOT"
	};
	char input;

	cin >> input;

	int cnt = 0;
	for (int i = 0; i < 3; ++i)
	{
		int j = 0;
		while (strs[i][j] != '\0')
		{
			if (strs[i][j] == input)
				++cnt;

			++j;
		}
	}

	cout << cnt;
	return 0;
}
