#include <iostream>

using namespace std;

int main(void)
{
	int input;
	cin >> input;

	int n1 = input % 10000;
	n1 = n1 / 1000;

	int n2 = input % 100;
	n2 = n2 / 10;

	int result = n1 * 10 + n2 + 5;

	cout << result;

	return 0;
}