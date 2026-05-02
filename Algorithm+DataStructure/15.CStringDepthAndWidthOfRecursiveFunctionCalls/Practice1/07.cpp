#include <iostream>
#include <cstring>

using namespace std;

void RecurPrint(const int _lev)
{
	cout << _lev << " ";

	if (_lev == 1) return;

	RecurPrint(_lev - 1);
	cout << _lev << " ";
}

int main()
{
	char str[100];

	cin >> str;

	RecurPrint(strlen(str));

	return 0;
}