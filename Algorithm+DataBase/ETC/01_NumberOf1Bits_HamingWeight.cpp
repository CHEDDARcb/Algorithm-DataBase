#include <iostream>

using namespace std;

int n;

int main(void)
{
	cin >> n;

	int hw = 0;
	while (n > 0)
	{
		if (n % 2 == 1)
			hw++;
		n /= 2;
	}

	cout << hw;
}