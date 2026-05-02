#include <iostream>

using namespace std;

int main(void)
{
	char* a, * b, * c;
	a = new char;
	b = new char;
	c = new char;

	cin >> *a >> *b >> *c;

	if (*a >= 'A' && *a <= 'Z' &&
		*b >= 'A' && *b <= 'Z' &&
		*c >= 'A' && *c <= 'Z')
	{
		cout << "모두대문자" << endl;
	}
	else
	{
		cout << "소문자있음" << endl;
	}

	return 0;
}