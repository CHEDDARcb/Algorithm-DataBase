#include <iostream>

using namespace std;

void RecurPrint(const int _a, const int _b)
{
	cout << _a;
	if (_a >= _b) return;
	RecurPrint(_a + 1, _b);
	cout << _a;
}

int main()
{
	int a, b;

	cin >> a >> b;

	RecurPrint(a, b);

	return 0;
}