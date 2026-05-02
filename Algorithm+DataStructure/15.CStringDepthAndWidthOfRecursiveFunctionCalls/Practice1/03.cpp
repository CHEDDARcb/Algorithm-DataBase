#include <iostream>

using namespace std;

void RecurFoo(int _curLev, const int _maxLev, const int _branch)
{
	if (_curLev == _maxLev) return;

	for (int i = 0; i < _branch; ++i)
	{
		RecurFoo(_curLev + 1, _maxLev, _branch);
	}
}

int main()
{
	int level, branch;

	cin >> level >> branch;

	RecurFoo(0, level, branch);

	return 0;
}