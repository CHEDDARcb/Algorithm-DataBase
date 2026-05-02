#include <iostream>

using namespace std;

int main(void)
{
	char c;

	cin >> c;

	if (c >= 'A' && c <= 'Z')
	{
		cout << "대문자입니다";
	}
	else if (c >= 'a' && c <= 'z')
	{
		cout << "소문자입니다";
	}

	return 0;
}