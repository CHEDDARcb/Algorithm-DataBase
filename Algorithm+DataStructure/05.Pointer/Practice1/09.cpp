#include <iostream>

using namespace std;

void INPUT(int* _input)
{
	cin >> *_input;
}

void CountDonw(const int _num)
{
	for (int i = _num; i >= 1; --i)
	{
		cout << i << " ";
	}
}

int main(void)
{
	int input;

	INPUT(&input);

	CountDonw(input);

	return 0;
}
