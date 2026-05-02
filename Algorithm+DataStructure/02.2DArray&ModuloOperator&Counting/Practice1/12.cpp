#include <iostream>

using namespace std;

int input;

void BBQ()
{
	if (input > 0 && input < 5)
		cout << "초기값" << endl;
	else if (input > 6 && input < 10)
		cout << "중간값" << endl;
	else
		cout << "알수없는값" << endl;
}

int main(void)
{
	cin >> input;

	if (input == 3 || input == 5 || input == 7)
		for (int i = 1; i <= 10; ++i)
			cout << i;
	else if (input == 0 || input == 8)
		for (int i = 10; i >= 1; --i)
			cout << i;
	else
		BBQ();

	return 0;
}