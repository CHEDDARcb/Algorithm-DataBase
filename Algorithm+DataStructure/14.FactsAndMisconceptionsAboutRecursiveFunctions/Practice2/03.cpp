#include <iostream>

using namespace std;

int main()
{
	char str[11];

	cin >> str;

	int len = strlen(str);
	if (len % 2 == 1)
	{
		cout << "다른 문장";
	}
	else
	{
		bool isSame = true;
		int searchLen = len / 2;
		for (int i = 0; i < searchLen; ++i)
		{
			if (str[i] != str[searchLen + i])
			{
				isSame = false;
				break;
			}
		}

		if (isSame)
			cout << "동일한문장";
		else
			cout << "다른문장";
	}
	return 0;
