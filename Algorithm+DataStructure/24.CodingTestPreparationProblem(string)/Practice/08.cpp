#include <iostream>

using namespace std;

int main(void)
{
	string strs[3];

	int minLen = INT_MAX;
	for (auto& str : strs)
	{
		cin >> str;
		if (str.length() < minLen) minLen = str.length();
	}

	char* result = new char[minLen + 1];

	bool isFind = false;
	int i = 0;
	for (; i < minLen; ++i)
	{
		if (strs[0][i] == strs[1][i] &&
			strs[0][i] == strs[2][i] &&
			strs[1][i] == strs[2][i])
		{
			isFind = true;
		}
		else
			break;
	}

	if (isFind)
	{
		int j = 0;
		for (j = 0; j < i; ++j)
			result[j] = strs[0][j];
		result[j] = '\0';

		cout << result;
	}
	else
		cout << "";

	return 0;
}