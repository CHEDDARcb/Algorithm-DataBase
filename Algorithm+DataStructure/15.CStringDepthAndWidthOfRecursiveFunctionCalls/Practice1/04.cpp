#include <iostream>

using namespace std;

void RecurFuc(const int _curLev, const int _maxLev)
{
	cout << _curLev;

	if (_curLev >= _maxLev)
		return;

	RecurFuc(_curLev + 1, _maxLev);
	RecurFuc(_curLev + 1, _maxLev);
}

int main()
{
	int maxLev;

	cin >> maxLev;

	RecurFuc(0, maxLev);

	return 0;
}