#include <iostream>

using namespace std;

void RecurPrint(const char _str[], const int _printLen, const int _maxDepth)
{
	for (int i = 0; i <= _printLen; ++i)
	{
		cout << _str[i];
	}
	cout << endl;

	if (_printLen == _maxDepth)
		return;

	RecurPrint(_str, _printLen + 1, _maxDepth);
}

int main()
{
	char str[256];

	cin >> str;

	int len = strlen(str);

	RecurPrint(str, 0, len - 1);

	return 0;
}