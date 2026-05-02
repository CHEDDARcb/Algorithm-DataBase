#include <iostream>

using namespace std;

int main(void)
{
	char str[9] = { 'D', 'A', 'T', 'A', 'P', 'O', 'W', 'E', 'R' };
	int a, b;

	cin >> a >> b;

	char cpyStr[9];
	int cpSize = 0;

	for (int i = a; i <= b; ++i)
	{
		cpyStr[cpSize++] = str[i];
	}

	for (int i = 0; i < cpSize; ++i)
	{
		cout << cpyStr[i];
	}

	return 0;
}