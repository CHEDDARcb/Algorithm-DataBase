#include <iostream>

using namespace std;
int main(void)
{
	string s;
	cin >> s;

	int result = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(')
			result += 1;
		else if (s[i] == '[')
			result += 2;
		else if (s[i] == '{')
			result += 3;
		else if (s[i] == ')')
			result -= 1;
		else if (s[i] == ']')
			result -= 2;
		else if (s[i] == '}')
			result -= 3;
	}

	cout << (result == 0 ? "true" : "false");
}