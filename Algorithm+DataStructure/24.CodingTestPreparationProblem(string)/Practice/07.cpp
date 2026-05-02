#include <iostream>

using namespace std;

int Find(const string& orgin, const string& patt)
{
	int originStart = 0;
	while (originStart <= orgin.length() - patt.length())
	{
		int o = originStart;
		int i = 0;
		for (; i < patt.length(); ++i)
		{
			if (orgin[o] != patt[i]) break;
			++o;
		}

		if (i == patt.length()) return originStart;

		++originStart;
	}

	return -1;
}

int main(void)
{
	string needle, haystack;

	cin >> haystack >> needle;

	int idx;
	if (haystack.length() < needle.length()) idx = -1;
	else idx = Find(haystack, needle);

	cout << idx;
}