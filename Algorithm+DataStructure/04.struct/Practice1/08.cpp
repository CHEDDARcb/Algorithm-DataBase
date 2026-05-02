#include <iostream>

using namespace std;

void BBQ(int _a, int _b)
{
	cout << "ÇÕ: " << _a + _b << endl;
	cout << "Â÷: " << _a - _b << endl;
	cout << "°ö: " << _a * _b << endl;
	cout << "¸ò: " << _a / _b << endl;
}
int main(void)
{
	int a, b;

	cin >> a >> b;

	BBQ(a, b);

	return 0;
}