#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str;

	cin >> str;

	for (int i = 0; i < str.length() / 2; ++i)
	{
		char tmp = str[i];
		str[i] = str[str.length() - 1 - i];
		str[str.length() - 1 - i] = tmp;
	}

	cout << str;

	return 0;
}