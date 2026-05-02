#include <iostream>

using namespace std;

int main(void)
{
	char c;

	cin >> c;

	if (c >= 'a' && c <= 'z')
	{
		cout << static_cast<char>(c - 'a' + 'A');
	}

	return 0;
}