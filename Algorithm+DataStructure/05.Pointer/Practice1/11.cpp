#include <iostream>

using namespace std;

char scoring()
{
	int input;

	cin >> input;

	return input >= 90 ? 'A' :
		input >= 80 ? 'B' :
		input >= 70 ? 'C' : 'D';

}

int main(void)
{
	cout << scoring();

	return 0;
}