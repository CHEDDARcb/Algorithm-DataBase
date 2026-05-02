#include <iostream>

using namespace std;

int main(void)
{
	char strs[2][9] =
	{
		"BackLog",
		"BackBt"
	};

	int len1 = 0;
	while (strs[0][len1++] != '\0') {}
	--len1;

	int len2 = 0;
	while (strs[1][len2++] != '\0') {}
	--len2;

	int difLen;
	if (len1 > len2)
	{
		difLen = len1 - len2;
		for (int i = 0; i < len2; ++i)
		{
			if (strs[0][i] != strs[1][i])
				++difLen;
		}
	}
	else
	{
		difLen = len2 - len1;
		for (int i = 0; i < len1; ++i)
		{
			if (strs[0][i] != strs[1][i])
				++difLen;
		}
	}

	cout << difLen;

	return 0;
}