#include <iostream>

using namespace std;

int main(void)
{
	char strs[2][256]{};

	cin >> strs[0] >> strs[1];

	for (int i = 0; i < 2; ++i)\
	{
		int size = 0;
		while (strs[i][size++] != '\0');
		--size;

		cout << size << " ";
	}

	return 0;
}