#include <iostream>

using namespace std;

int main(void)
{
	char c;
	int n;

	cin >> c >> n;

	int i = 0;
	while (i < n)
	{
		int j = 0;
		while (j < n)
		{
			cout << c << " ";
			++j;
		}
		cout << endl;
		++i;
	}

	return 0;
}