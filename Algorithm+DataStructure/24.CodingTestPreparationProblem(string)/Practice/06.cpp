#include <iostream>
#include <string>

using namespace std;

bool IsSignOrNum(char c)
{
	return (c >= '0' && c <= '9') ||
		(c == '+' || c == '-');

}

bool IsNum(char c)
{
	return (c >= '0' && c <= '9');

}

int myAtoi(string s)
{
	int i = 0;
	for (; i < s.length(); ++i)
	{
		if (s[i] == ' ') continue;

		if (IsSignOrNum(s[i]))
			break;
		else return 0;
	}

	int startIdx = i;
	int sign;
	if (s[startIdx] == '-')
	{
		sign = -1;
		++startIdx;
	}
	else
	{
		sign = 1;
		if (s[startIdx] == '+')
			++startIdx;
	}

	int result = 0;
	for (int i = startIdx; i < s.length(); ++i)
	{
		if (!IsNum(s[i])) break;

		int d = s[i] - '0';
		result = result * 10 + d;
	}

	return result * sign;
}

int main(void)
{
	string input;

	getline(cin, input);

	int result = myAtoi(input);

	cout << result;

	return 0;
}
