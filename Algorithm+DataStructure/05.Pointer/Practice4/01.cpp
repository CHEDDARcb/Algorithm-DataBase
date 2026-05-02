#include <iostream>

using namespace std;

int main(void)
{
	char arr[6] = { 'D', 'F', 'G', 'D', 'A', 'Q' };
	char a, b;

	cin >> a >> b;

	for (int i = 0; i < 6; ++i)
	{
		for (char j = a; j <= b; ++j)
		{
			if (arr[i] == j)
			{
				cout << "발견!!!";
				return 0;
			}
		}
	}

	cout << "미발견!!!";
	return 0;
}
