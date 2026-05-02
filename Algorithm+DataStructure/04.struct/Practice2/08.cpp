#include <iostream>

using namespace std;

void BBQ(int _num)
{
	for (int i = 1; i <= _num; ++i)
	{
		cout << i << " ";
	}
}

void KFC(char _ch)
{
	for (int i = 0; i < 7; ++i)
	{
		cout << _ch;
	}
}

int main(void)
{
	int input1;

	cin >> input1;

	if (input1 % 2)
	{
		int inputN;
		cin >> inputN;

		BBQ(inputN);
	}
	else
	{
		char inputC;
		cin >> inputC;

		KFC(inputC);
	}

	return 0;
}
