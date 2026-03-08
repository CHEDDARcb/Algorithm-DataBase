#include <iostream>

using namespace std;

int n;

int RecursiveBS(int s, int e)
{
	if (s >= e)
		return s;

	int m = (s + e + 1) / 2;
	if (m * m == n)
		return m;
	else if (m * m < n)
		RecursiveBS(m, e);
	else
		RecursiveBS(s, m - 1);
}

int main(void)
{
	cin >> n;

	int result = RecursiveBS(0, n);
	cout << result << endl;

	return 0;
}