#include <iostream>

using namespace std;

int main(void)
{
	int a, b;

	cin >> a >> b;

	while (a <= b)
	{
		cout << a << " ";
		++a;
	}

	return 0;
}