#include <iostream>

using namespace std;

int main(void)
{
	int input;

	cin >> input;

	int a, b, c, d;

	a = input / 1000;
	input %= 1000;

	b = input / 100;
	input %= 100;

	c = input / 10;
	input %= 10;

	d = input;

	cout << "숫자" << a << endl;
	cout << "숫자" << b << endl;
	cout << "숫자" << c << endl;
	cout << "숫자" << d << endl;
}