#include <iostream>

using namespace std;

char arr[17];

void input()
{
	char c1, c2, c3;

	cin >> c1 >> c2 >> c3;
	for (int i = 0; i < 17; ++i)
	{
		if (i <= 6)
			arr[i] = c1;
		else if (i >= 7 && i <= 12)
			arr[i] = c2;
		else
			arr[i] = c3;
	}
}

int main(void)
{
	input();

	for (int i = 16; i >= 0; --i)
	{
		cout << arr[i] << endl;
	}

	return 0;
}