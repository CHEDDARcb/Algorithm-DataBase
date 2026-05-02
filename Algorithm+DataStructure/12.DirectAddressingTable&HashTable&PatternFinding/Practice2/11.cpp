#include <iostream>

using namespace std;

bool HasPattern(const char _base[], const char _pattern[],
	const size_t _pSize, const size_t _startIdx)
{
	for (size_t i = 0; i < _pSize; ++i)
	{
		if (_base[_startIdx + i] != _pattern[i])
			return false;
	}

	return true;
}

int main()
{
	const char pattern[6] = "GHOST";
	char str[256];

	cin >> str;

	int patternLen = strlen(pattern);
	int strLen = strlen(str);

	int hasPattern = false;
	for (int i = 0; i < strLen - patternLen + 1; ++i)
	{
		if (HasPattern(str, pattern, patternLen, i))
		{
			hasPattern = true;
			break;
		}
	}

	if (hasPattern)
		cout << "존재";
	else
		cout << "존재하지 않음";

	return 0;
}