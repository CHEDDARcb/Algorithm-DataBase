#include <iostream>
#include <vector>

using namespace std;

int n;
vector<bool> isPrime;

int main(void)
{
	cin >> n;

	if (n <= 2)
	{
		cout << 0;
		return 0;
	}

	isPrime.resize(n + 1, true);
	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i * i < n; ++i)
	{
		if (!isPrime[i]) continue;

		for (int j = i * i; j < n; j += i)
			isPrime[i] = false;
	}

	int cnt = 0;
	for (int i = 2; i < n; ++i)
		if (isPrime[i]) ++cnt;

	cout << cnt;

	return 0;
}