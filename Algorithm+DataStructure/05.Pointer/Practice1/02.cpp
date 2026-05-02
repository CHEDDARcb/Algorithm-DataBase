#include <iostream>

using namespace std;

char getChar()
{
	char c1, c2;

	cin >> c1 >> c2;

	return c1 > c2 ? c1 : c2;
}

int main(void)
{
	cout << getChar();

	return 0;
}