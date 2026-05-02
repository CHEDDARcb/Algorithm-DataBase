#include <iostream>

using namespace std;

int main(void)
{
	char str[100];

	cin >> str;

	int strSize = 0;
	while (str[strSize++] != '\0') {}
	--strSize;

	//Bubble
	for (int i = 0; i < strSize - 1; ++i)
	{
		for (int j = 0; j < strSize - 1 - i; ++j)
		{
			if (str[j] > str[j + 1])
			{
				int tmp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = tmp;
			}
		}
	}

	//Select
	// for (int p = 0; p < strSize - 1; ++p)
	// {
	// 	int m = p;
	// 	for (int i = p + 1; i < strSize; ++i)
	// 	{
	// 		if (str[m] > str[i])
	// 			m = i;
	// 	}
	// 
	// 	char tmp = str[m];
	// 	str[m] = str[p];
	// 	str[p] = tmp;
	// }


	cout << str;

	return 0;
}