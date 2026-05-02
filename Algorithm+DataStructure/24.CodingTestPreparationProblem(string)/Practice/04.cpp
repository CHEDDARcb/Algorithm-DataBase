#include <iostream>
#include <string>

using namespace std;

int dma1[26]{};
int dma2[26]{};

int main(void)
{
	string s, t;

	cin >> s >> t;

	if (s.length() != t.length())
	{
		cout << "false";
		return 0;
	}

	for (int i = 0; i < s.length(); ++i)
	{
		dma1[s[i] - 'a']++;
		dma2[t[i] - 'a']++;
	}

	bool isOk = true;
	for (int i = 0; i < 26; ++i)
	{
		if (dma1[i] != dma2[i])
		{
			isOk = false;
			break;
		}
	}

	cout << (isOk ? "true" : "false");

	return 0;
}
