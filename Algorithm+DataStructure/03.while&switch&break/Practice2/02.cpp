#include <iostream>

using namespace std;

int main(void)
{
	char arr[6] = { 'D', 'T', 'A', 'B', 'W', 'Q' };
	char c;

	cin >> c;
	for (int i = 0; i < 6; ++i)
	{
		if (c == arr[i])
			cout << i << "¹ø INDEX" << endl;
	}

	return 0;
}