#include <iostream>

using namespace std;

void RecurDivide(int _num)
{
	if (_num == 0) return;
	RecurDivide(_num / 2);
	cout << _num << " ";
}

int main()
{
	int input;

	cin >> input;

	RecurDivide(input);

	return 0;
}