#include <iostream>

using namespace std;

void CountDown(int n)
{
	cout << n << " ";
	if (n <= 0) return;
	CountDown(n - 1);
	cout << n << " ";

}

int main()
{
	int n;

	cin >> n;
	CountDown(n);

	return 0;
}