#include <iostream>

using namespace std;

int main(void)
{
	char str[11];

	cin >> str;

	for (int i = 0; str[i] != '\0'; ++i)
	{
		if ((i + 1) % 2)
		{
			if (!(str[i] >= 'A' && str[i] <= 'Z'))
			{
				cout << "일반문장";
				return 0;
			}
		}
		else
		{
			if (!(str[i] >= 'a' && str[i] <= 'z'))
			{
				cout << "일반문장";
				return 0;
			}
		}
	}

	cout << "개구리 문장";

	return 0;
}