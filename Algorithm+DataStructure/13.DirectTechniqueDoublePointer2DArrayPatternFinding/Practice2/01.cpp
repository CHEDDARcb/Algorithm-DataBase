#include <iostream>

using namespace std;

void BBQ(int* _a, int* _b)
{
	int max = INT_MIN;
	int min = INT_MAX;

	int input;
	for (int i = 0; i < 5; ++i)
	{
		cin >> input;
		if (max < input)
			max = input;
		if (min > input)
			min = input;
	}

	*_a = max;
	*_b = min;
}

int main()
{
	int a, b;

	BBQ(&a, &b);

	cout << 'a' << "=" << a << endl;
	cout << 'b' << "=" << b << endl;

	return 0;
}