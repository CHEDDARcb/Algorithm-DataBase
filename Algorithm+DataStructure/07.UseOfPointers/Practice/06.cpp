#include <iostream>

using namespace std;

int main(void)
{
	char arr[2][7]
	{
		"457132",
		"DFQWGZ"
	};
	char input;

	cin >> input;
	for (int i = 0; i < 6; ++i)
	{
		if (arr[0][i] == input)
		{
			cout << arr[1][i];
			break;
		}
	}

	return 0;
}