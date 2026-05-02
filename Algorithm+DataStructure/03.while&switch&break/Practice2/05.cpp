#include <iostream>

using namespace std;

int main(void)
{
	char c1, c2;
	int num;

	cin >> c1 >> c2 >> num;

	for (int i = 0; i < num; ++i)
	{
		for (char i = c1; i <= c2; ++i)
		{
			cout << i;
		}

		cout << endl;
	}

	return 0;
}