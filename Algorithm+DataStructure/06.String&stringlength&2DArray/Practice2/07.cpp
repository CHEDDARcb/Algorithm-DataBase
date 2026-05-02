#include <iostream>

using namespace std;

int main(void)
{
	char str[3][100];

	cin >> str[0] >> str[1] >> str[2];

	int maxSize = INT_MIN;
	int maxIdx = -1;
	for (int i = 0; i < 3; ++i)
	{
		int size = 0;
		while (str[i][size++] != '\0') {}
		--size;

		if (maxSize < size)
		{
			maxSize = size;
			maxIdx = i;
		}
	}

	cout << str[maxIdx];

	return 0;
}