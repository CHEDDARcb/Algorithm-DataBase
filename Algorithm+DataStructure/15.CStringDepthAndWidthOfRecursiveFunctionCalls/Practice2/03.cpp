#include <iostream>

using namespace std;

int FindTarget(const char _str[], const char _target)
{
	for (int i = 0; _str[i] != '\0'; ++i)
	{
		if (_str[i] == _target)
			return i;
	}
}

void PushSharp(char _str[], const int _len, const int _idx)
{
	int sIdx1 = _idx - 1;
	int sIdx2 = _idx + 1;

	if (sIdx1 >= 0 && sIdx1 < _len)
		_str[sIdx1] = '#';
	if (sIdx2 >= 0 && sIdx2 < _len)
		_str[sIdx2] = '#';
}

int main()
{
	char str[100];
	char c1, c2;

	cin >> str >> c1 >> c2;

	int idx1 = FindTarget(str, c1);
	int idx2 = FindTarget(str, c2);

	int len = strlen(str);

	PushSharp(str, len, idx1);
	PushSharp(str, len, idx2);

	cout << str;

	return 0;
}