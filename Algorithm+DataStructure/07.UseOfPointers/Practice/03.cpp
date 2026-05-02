#include <iostream>

using namespace std;

int stringLen(char str[])
{
	int len = 0;
	while (str[len++] != '\0') {}
	return --len;
}

int main(void)
{
	char input[100];
	cin >> input;

	cout << stringLen(input) << "±ÛÀÚ";

	return 0;
}