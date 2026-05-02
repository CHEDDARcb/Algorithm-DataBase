#include <iostream>

using namespace std;

int main()
{
	char str[10];
	cin >> str;

	int len = strlen(str);
	for (int i = len - 1; i >= 0; --i)
	{
		for (int j = i; j <= len - 1; ++j)
		{
			cout << str[j];
		}
		cout << endl;
	}

	return 0;
}