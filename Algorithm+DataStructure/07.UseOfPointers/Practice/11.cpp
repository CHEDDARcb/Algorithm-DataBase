#include <iostream>

using namespace std;

int main(void)
{
	int a[5];
	int b[5];
	int c[5];

	for (int i = 0; i < 5; ++i)
		cin >> a[i];
	for (int i = 0; i < 5; ++i)
		cin >> b[i];
	for (int i = 0; i < 5; ++i)
		cin >> c[i];

	for (int i = 0; i < 5; ++i)
	{
		cout << a[i] * b[i] + c[i] << " ";
	}

	return 0;
}