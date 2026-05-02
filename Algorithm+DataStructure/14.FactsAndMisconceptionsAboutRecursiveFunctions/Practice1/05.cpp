#include <iostream>

using namespace std;

void RecurPrint(const char _str[], int _idx, const int _maxDepth)
{
	if (_idx >= _maxDepth)
	{
		cout << endl;
		return;
	}
	cout << _str[_idx];
	RecurPrint(_str, _idx + 1, _maxDepth);
	cout << _str[_idx];
}

int main()
{
	char str[5] = { 'a', 'b', 'c', 'd', 'e' };

	RecurPrint(str, 0, 5);

	return 0;
}