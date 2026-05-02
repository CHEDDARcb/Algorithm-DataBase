#include <iostream>

using namespace std;

int main(void)
{
	char str[11];

	cin >> str;

	if (str[0] == 'F')
	{
		cout << "Â¦ÀÌ ¾È ¸ÂÀ½";
		return 0;
	}

	int count = 0;
	int len = strlen(str);
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == 'B')
			count++;
		else if (str[i] == 'F')
		{
			count--;
			if (count < 0) break;
		}
	}

	if (count)
		cout << "Â¦ÀÌ ¾È ¸ºÀ½";
	else
		cout << "Â¦ÀÌ ¸ÂÀ½";

	return 0;
}