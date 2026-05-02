#include <iostream>

using namespace std;

int main(void)
{
	int num;

	cin >> num;

	for (int i = 0; i < 6; ++i)
	{
		if (i >= 0 && i <= 2)
		{
			for (int j = 0; j < 4; ++j)
			{
				cout << num;
			}
		}
		else
		{
			for (int j = 0; j < 3; ++j)
			{
				cout << num;
			}
		}
		cout << endl;
	}

	return 0;
}