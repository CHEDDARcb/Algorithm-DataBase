#include <iostream>

using namespace std;

void Swap(int* _a, int* _b)
{
	int temp = *_a;
	*_a = *_b;
	*_b = temp;
}
int main(void)
{
	int a, b;

	cin >> a >> b;

	Swap(&a, &b);

	cout << a << " " << b;

	return 0;
}