#include <iostream>

using namespace std;

char arr1[5] = { 'B', 'D', '5', 'Q', 'A' };
char arr2[5] = { 'Q', 'E', 'R', 'E', 'F' };
char c;

void input()
{
	cin >> c;
}

void output()
{
	if (c >= 'a' && c <= 'z')
		for (const auto& data : arr1)
			cout << data;
	else if (c >= 'A' && c <= 'Z')
		for (const auto& data : arr2)
			cout << data;
	else if (c >= '0' && c <= '9')
		for (char i = 'H'; i >= 'A'; --i)
			cout << i;
}

int main(void)
{
	input();
	output();

	return 0;
}