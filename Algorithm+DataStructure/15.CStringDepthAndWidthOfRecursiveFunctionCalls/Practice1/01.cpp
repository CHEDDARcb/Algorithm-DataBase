#include <iostream>
#include <cstring>

using namespace std;

void Foo(int _level, const int _maxLevel = 2)
{
	if (_level == _maxLevel) return;

	Foo(_level + 1);
	Foo(_level + 1);
	Foo(_level + 1);
}

int main()
{
	const int maxLevel = 3;
	Foo(0, maxLevel);
	return 0;
}