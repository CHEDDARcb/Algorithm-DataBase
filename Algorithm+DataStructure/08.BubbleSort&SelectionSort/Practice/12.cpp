#include <iostream>

using namespace std;

int main(void)
{
	const char const strs[3][6] =
	{
		"POTIO",
		"ABCDE",
		"YOURE"
	};
	int a, b;

	cin >> a >> b;

	for (const auto& str : strs)
	{
		for (int i = a; i <= b; ++i)
		{
			cout << str[i];
		}
	}

	return 0;
}