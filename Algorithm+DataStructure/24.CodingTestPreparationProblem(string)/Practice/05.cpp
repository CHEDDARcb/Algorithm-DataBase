#include <string>

using namespace std;

bool IsAlphaNum(char c)
{
	return (c >= 'A' && c <= 'Z') ||
		(c >= 'a' && c <= 'z') ||
		(c >= '0' && c <= '9');

}

int main(void)
{
	string input;

	getline(cin, input);

	int f = 0;
	int l = input.length() - 1;
	bool isOk = true;
	while (f <= l)
	{
		while (f < l && !IsAlphaNum(input[f])) ++f;
		while (f < l && !IsAlphaNum(input[l])) --l;

		char fc = input[f];
		char lc = input[l];

		if (fc >= 'A' && fc <= 'Z') fc = fc - 'A' + 'a';
		if (lc >= 'A' && lc <= 'Z') lc = lc - 'A' + 'a';

		if (fc != lc)
		{
			isOk = false;
			break;
		}
		++f;
		--l;
	}

	cout << (isOk ? "true" : "false");

	return 0;
}