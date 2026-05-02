#include <iostream>

using namespace std;

int main(void)
{
	int input;

	cin >> input;

	for (int i = 0; i < input; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			cout << j;
		}
		cout << endl;
	}

	return 0;
}