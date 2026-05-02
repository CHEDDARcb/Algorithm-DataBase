#include <iostream>

using namespace std;

int main(void)
{
	char c;

	cin >> c;

	for (char i = c; i >= 'a'; --i)
	{
		cout << i;
	}

	return 0;
}