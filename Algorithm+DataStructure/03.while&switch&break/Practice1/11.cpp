#include <iostream>

using namespace std;

void startBox()
{
	for (int i = 1; i <= 20; ++i)
		if (i % 2)
			cout << i << " ";
}

void maxDoll()
{
	for (char i = 'H'; i >= 'A'; --i)
		cout << i << " ";
}

void copyBean()
{
	for (int i = -5; i <= 5; ++i)
		cout << i << " ";
}

int main(void)
{
	int input;

	cin >> input;

	if (input >= 3500 && input <= 5000)
		startBox();
	else if (input >= 2500 && input < 3500)
		maxDoll();
	else
		copyBean();

	return 0;
}