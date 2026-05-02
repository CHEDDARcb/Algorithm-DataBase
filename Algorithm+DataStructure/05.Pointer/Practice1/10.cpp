#include <iostream>

using namespace std;

int yesOrNo()
{
	int input;

	cin >> input;

	int result = input % 3;

	return result == 0 ? 7 :
		result == 1 ? 35 : 50;
}

int main(void)
{
	cout << yesOrNo();

	return 0;
}
