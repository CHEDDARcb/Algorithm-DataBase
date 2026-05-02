#include <iostream>

using namespace std;

int HashFunction(const string& str)
{
	int h = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		h = h * 26 + str[i];
	}

	return h;
}

int main(void)
{
	string input;
	cin >> input;

	cout << HashFunction(input);

	return 0;
}