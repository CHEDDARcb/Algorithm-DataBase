#include <iostream>

using namespace std;

int main()
{
	char str[11];
	cin >> str;

	int dAT[256]{};
	for (int i = 0; str[i] != '\0'; ++i)
	{
		int idx = static_cast<int>(str[i]);
		++dAT[idx];
	}

	for (int i = 'A'; i <= 'Z'; ++i)
	{
		if (dAT[i])
		{
			cout << static_cast<char>(i) << ": " << dAT[i] << endl;
		}
	}
	return 0;
}