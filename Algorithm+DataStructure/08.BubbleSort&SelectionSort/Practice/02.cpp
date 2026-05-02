#include <iostream>

using namespace std;

int main(void)
{
	int input;

	cin >> input;

	int i = 0;
	while (i < 3)
	{
		int j = 0;
		while (j < 5)
		{
			cout << input;
			++j;
		}
		cout << endl;
		++i;
	}

	return 0;
}