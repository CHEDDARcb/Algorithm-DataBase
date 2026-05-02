#include <iostream>

using namespace std;

void abc(int a, int b, int* sum, int* gop)
{
	*sum = a + b;
	*gop = a * b;
}

int main(void)
{
	int a, b;

	cin >> a >> b;

	int  sum, gop;
	abc(a, b, &sum, &gop);

	cout << sum << " " << gop << endl;

	return 0;
}