#include <iostream>

using namespace std;

char arr[7] = { 'M', 'I', 'N', 'Q', 'U', 'E', 'S' };

int Length(char c)
{
	for (int i = 0; i < 7; ++i)
	{
		if (arr[i] == c)
			return i;
	}

	return -1;
}

int main(void)
{
	char c1, c2, c3;

	cin >> c1 >> c2 >> c3;

	cout << c1 << "=" << Length(c1) << endl;
	cout << c2 << "=" << Length(c2) << endl;
	cout << c3 << "=" << Length(c3) << endl;
	return 0;
}
