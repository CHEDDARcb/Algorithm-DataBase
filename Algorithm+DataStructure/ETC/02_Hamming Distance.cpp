#include <iostream>

using namespace std;

int main(void)
{
	int x, y;

	cin >> x >> y;

	int target = x ^ y;
	int cnt = 0;
	while (target)
	{
		target &= (target - 1);
		++cnt;
	}

	cout << cnt;

	return 0;
}

