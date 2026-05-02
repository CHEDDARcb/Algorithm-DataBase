#include <iostream>

using namespace std;

int main(void)
{
	char c1, c2;
	int dist;

	cin >> c1 >> c2;

	for (int i = 0; i < 4; ++i)
	{
		for (char c = c1; c <= c2; ++c)
		{
			cout << c << " ";
		}

		cout << endl;
	}

	return 0;
}