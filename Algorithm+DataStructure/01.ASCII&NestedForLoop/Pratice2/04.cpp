#include <iostream>

using namespace std;

int main(void)
{
	char c;

	cin >> c;

	if (c >= 'a' && c <= 'z')
	{
		cout << "소문자입력!!";
	}
	else if (c >= 'A' && c <= 'Z')
	{
		cout << "대문자입력!!";
	}
	else if (c >= '0' && c <= '9')
	{
		cout << "숫자문자입력!!";
	}

	return 0;
}