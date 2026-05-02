#include <iostream>

using namespace std;

string fuel;

int main(void)
{
	cin >> fuel;

	int s = 0;
	int e = fuel.size() - 1;

	while (s < e)
	{
		int m = (s + e + 1) / 2;
		if (fuel[m] == '#')
			s = m;
		else
			e = m - 1;
	}

	int p = (s + 1) * 10;
	cout << p << "%";

	return 0;
}