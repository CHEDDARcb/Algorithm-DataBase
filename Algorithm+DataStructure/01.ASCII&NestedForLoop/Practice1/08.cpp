#include <iostream>

using namespace std;

int main(void)
{
	char input;

	cin >> input;

	if (input >= '0' && input <= '9')
	{
		cout << static_cast<int>(input - '0') + 5;
	}

	return 0;
}