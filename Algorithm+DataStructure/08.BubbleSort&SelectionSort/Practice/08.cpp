#include <iostream>

using namespace std;

void CountLine(char (*strs)[10])
{
	for (int i = 0; i < 3; ++i)
	{
		int len = 0;
		while (strs[i][len++] != '\0') {}
		len--;

		cout << len << '=' << strs[i] << endl;
	}
}

int main(void)
{
	char strs[3][10];

	cin >> strs[0] >> strs[1] >> strs[2];

	CountLine(strs);

	return 0;
}